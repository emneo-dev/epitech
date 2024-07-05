module HALEval where

import Data.Functor
import Data.Map.Strict
import Data.Maybe
import HALAbstractSyntaxtTree
import HALParsing
import Text.Read (readMaybe)
import Prelude hiding (lookup)

data RTProc
  = RTProcHs ([RTVal] -> Throws RTVal)
  | RTProcLp [String] ASTExpr Env

instance Show RTProc where
  show (RTProcHs _) = "RTProcHs"
  show RTProcLp {} = "RTProcLp"

data RTVal
  = RTValInt Integer
  | RTValBool Bool
  | RTValStr String
  | RTValNil
  | RTValCons RTVal RTVal
  | RTProc RTProc
  | RTAtom String

unwordsCons :: RTVal -> String
unwordsCons (RTValCons a b@(RTValCons _ _)) =
  show a ++ " " ++ unwordsCons b
unwordsCons (RTValCons a RTValNil) = show a
unwordsCons (RTValCons a b) =
  show a ++ " . " ++ show b
unwordsCons _ = error "unwordsCons: what just happened ???"

instance Show RTVal where
  show (RTValInt i) = show i
  show (RTValBool False) = "#f"
  show (RTValBool True) = "#t"
  show (RTValStr s) = s
  show RTValNil = "nil"
  show h@(RTValCons _ _) = "(" ++ unwordsCons h ++ ")"
  show (RTProc _) = "#<procedure>"
  show (RTAtom s) = s

data Error
  = NumArgs Integer [AST]
  | TypeMismatch String AST
  | BadSpecialForm String AST
  | NotFunction String String
  | UnboundVar String String
  | Default String
  | ParserError -- It shouldn't be here

instance Show Error where
  show (UnboundVar message varname) = message ++ ": " ++ varname
  show (BadSpecialForm message form) = message ++ ": " ++ show form
  show (NotFunction message func) = message ++ ": " ++ show func
  show (NumArgs expected found) =
    "Expected " ++ show expected
      ++ " args; found values "
      ++ unwordsList found
  show (TypeMismatch expected found) =
    "Invalid type: expected " ++ expected
      ++ ", found "
      ++ show found
  show (Default message) = message
  show ParserError = "Parser error :( (Big sad)"

type Throws = Either Error

throw :: Error -> Throws a
throw = Left

-- START OF BUILTINS

plus :: [RTVal] -> Throws RTVal
plus [RTValInt i1, RTValInt i2] = return $ RTValInt (i1 + i2)
plus (x:xs) = do
  y <- plus xs
  plus [x, y]
plus _ = throw $ Default "+: invalid arguments"

minus :: [RTVal] -> Throws RTVal
minus [RTValInt i] = return $ RTValInt (-i)
minus [RTValInt i1, RTValInt i2] = return $ RTValInt (i1 - i2)
minus (x:xs) = do
  y <- minus xs
  minus [x, y]
minus _ = throw $ Default "-: invalid arguments"

mul :: [RTVal] -> Throws RTVal
mul [RTValInt i1, RTValInt i2] = return $ RTValInt (i1 * i2)
mul (x:xs) = do
  y <- mul xs
  mul [x, y]
mul _ = throw $ Default "*: invalid arguments"

divi :: [RTVal] -> Throws RTVal
divi [RTValInt i1, RTValInt i2] = return $ RTValInt (i1 `div` i2)
divi _ = throw $ Default "div: invalid arguments"

modu :: [RTVal] -> Throws RTVal
modu [RTValInt i1, RTValInt i2] = return $ RTValInt (i1 `mod` i2)
modu _ = throw $ Default "mod: invalid arguments"

car :: [RTVal] -> Throws RTVal
car [RTValCons h _] = return h
car a = throw $ Default "car: invalid arguments"

cons :: [RTVal] -> Throws RTVal
cons [h, t] = return $ RTValCons h t
cons _ = throw $ Default "cons: invalid arguments"

cdr :: [RTVal] -> Throws RTVal
cdr [RTValCons _ t] = return t
cdr _ = throw $ Default "cdr: invalid arguments"

eq :: [RTVal] -> Throws RTVal
eq [RTValInt i1, RTValInt i2] = return $ RTValBool (i1 == i2)
eq [RTValStr s1, RTValStr s2] = return $ RTValBool (s1 == s2)
eq [RTValBool b1, RTValBool b2] = return $ RTValBool (b1 == b2)
eq [RTValNil, RTValNil] = return $ RTValBool True
eq [RTAtom s1, RTAtom s2] = return $ RTValBool (s1 == s2)
eq [_, _] = return $ RTValBool False
eq _ = throw $ Default "eq?: invalid arguments"

lt :: [RTVal] -> Throws RTVal
lt [RTValInt i1, RTValInt i2] = return $ RTValBool (i1 < i2)
lt _ = throw $ Default "<: invalid arguments"

isAtom :: [RTVal] -> Throws RTVal
isAtom [RTValNil] = return $ RTValBool True
isAtom [RTAtom _] = return $ RTValBool True
isAtom [RTValCons _ _] = return $ RTValBool False
isAtom _ = throw $ Default "atom?: invalid arguments"


-- END OF BUILTINS

type Env = Map String RTProc

getEmptyEnv :: Env
getEmptyEnv = fromList [ ("+", RTProcHs plus), ("-", RTProcHs minus),
  ("*", RTProcHs mul), ("div", RTProcHs divi), ("car", RTProcHs car),
  ("cons", RTProcHs cons), ("cdr", RTProcHs cdr), ("eq?", RTProcHs eq),
  ("mod", RTProcHs modu), ("<", RTProcHs lt), ("atom?", RTProcHs isAtom) ]

createRTVal :: Env -> ASTExpr -> Throws RTVal
createRTVal env e = do
  (res, _) <- evalExpr env e
  return res

createRTVals :: Env -> [ASTExpr] -> Throws [RTVal]
createRTVals env = mapM (createRTVal env)

isValPresent :: Env -> String -> Bool
isValPresent env var = isJust $ lookup var env

getVal :: Env -> String -> Throws RTProc
getVal env var = case lookup var env of
  Just val -> return val
  Nothing -> throw $ UnboundVar ("Variable not found: " ++ show env) var

setVal :: Env -> String -> RTProc -> Env
setVal env var val = insert var val env

launchHsProc :: Env -> RTProc -> [ASTExpr] -> Throws RTVal
launchHsProc env (RTProcHs func) args = case createRTVals env args of
  Right rtvals -> func rtvals
  Left e -> throw $ Default $ "Invalid arguments" ++ show args ++ " " ++ show e
launchHsProc _ _ _ = throw $ Default "Not a function"

createLpEnv :: Env -> [String] -> [ASTExpr] -> Throws Env
createLpEnv env [] [] = return env
createLpEnv _ [] a = throw $ Default ("Too many arguments" ++ show a)
createLpEnv _ _ [] = throw $ Default "Too few arguments"
createLpEnv env (var : vars) (arg : args) = do
  val <- createRTVal env arg
  createLpEnv (setVal env var (RTProcHs (\x -> return val))) vars args

launchLpProc :: Env -> [String] -> ASTExpr -> [ASTExpr] -> Throws RTVal
launchLpProc env vars expr args = do
  env' <- createLpEnv env vars args
  (res, _) <- evalExpr env' expr
  return res

callProc :: Env -> RTProc -> [ASTExpr] -> Throws RTVal
callProc env f@(RTProcHs func) args =
  case launchHsProc env f args of
    Right rtval -> return rtval
    Left err -> throw err
callProc env (RTProcLp formals body env') args =
  launchLpProc env formals body args

getProcAndLaunch :: Env -> String -> [ASTExpr] -> Throws RTVal
getProcAndLaunch env var args = do
  func <- getVal env var
  callProc env func args

evalCond :: Env -> [(ASTExpr, ASTExpr)] -> Throws RTVal
evalCond env [] = throw $ Default "No else clause"
evalCond env (x : xs) = do
  (cond, _) <- evalExpr env (fst x)
  case cond of
    RTValBool True -> createRTVal env (snd x)
    RTValBool False -> evalCond env xs
    _ -> throw $ Default "Conditional expression must be boolean"

evalLet :: Env -> [(ASTExpr, ASTExpr)] -> ASTExpr -> Throws RTVal
evalLet env [] expr = do
  (res, _) <- evalExpr env expr
  return res
evalLet env ((ASTVar var, x) : xs) expr = do
  val <- createRTVal env x
  evalLet (setVal env var (RTProcHs (\x -> return val))) xs expr
evalLet _ r _ = throw $ Default $ show r

createQuoted :: Datum -> RTVal
createQuoted (List []) = RTValNil
createQuoted (List [x]) = RTValCons (createQuoted x) RTValNil
createQuoted (List (x : xs)) =
  RTValCons (createQuoted x) (createQuoted (List xs))
createQuoted (DottedList [] x) = createQuoted x
createQuoted (DottedList [x] y) =
  RTValCons (createQuoted x) (createQuoted y)
createQuoted (DottedList (x : xs) y) =
  RTValCons (createQuoted x) (createQuoted (DottedList xs y))
createQuoted (Atom "#t") = RTValBool True
createQuoted (Atom "#f") = RTValBool False
createQuoted (Atom a) = RTAtom a
createQuoted (LitNumber i) = RTValInt i

evalExpr :: Env -> ASTExpr -> Throws (RTVal, Env)
evalExpr env (ASTNumber i) = return (RTValInt i, env)
evalExpr env (ASTBool b) = return (RTValBool b, env)
evalExpr env (ASTString s) = return (RTValStr s, env)
evalExpr env (ASTApplication func args) = do
  res <- getProcAndLaunch env func args
  return (res, env)
evalExpr env (ASTLambda formals body) =
  return (RTProc $ RTProcLp formals body env, env)
evalExpr env (ASTVar var) = do
  res <- getProcAndLaunch env var []
  return (res, env)
evalExpr env (ASTCond args) = do
  res <- evalCond env args
  return (res, env)
evalExpr env (ASTLet bindings expr) = do
  res <- evalLet env bindings expr
  return (res, env)
evalExpr env (ASTQuote a) = return (createQuoted a, env)
evalExpr env (ASTLambdaApplication a@(ASTLambda _ _) args) = do
  case evalExpr env a of
    Right (RTProc lb, _) -> do
      res <- callProc env lb args
      return (res, env)
    Left err -> throw err
    _ -> throw $ Default "Not a function"
evalExpr _ _ = throw $ Default "Invalid AST"

evalDef :: Env -> ASTDef -> Throws (RTVal, Env)
evalDef env (Define var (ASTLambda formals body)) =
  return (RTProc val, env')
  where
    env' = setVal env var val
    val = RTProcLp formals body env
evalDef env (Define var expr) =
  return (RTProc val, env')
  where
    env' = setVal env var val
    val = RTProcLp [] expr env

eval :: Env -> AST -> Throws (RTVal, Env)
eval env (ASTExpr r) = evalExpr env r
eval env (ASTDef r) = evalDef env r
