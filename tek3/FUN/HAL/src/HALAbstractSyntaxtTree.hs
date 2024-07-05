module HALAbstractSyntaxtTree where

import Control.Applicative
import Data.Char
import Data.Functor ((<&>))
import Data.List.NonEmpty (NonEmpty ((:|)))
import HALParsing
import Text.Read (readMaybe)

data ASTExpr
  = ASTNumber Integer
  | ASTString String
  | ASTBool Bool
  | ASTCond [(ASTExpr, ASTExpr)]
  | ASTLet [(ASTExpr, ASTExpr)] ASTExpr
  | ASTQuote Datum
  | ASTLambda [String] ASTExpr
  | ASTApplication String [ASTExpr]
  | ASTLambdaApplication ASTExpr [ASTExpr]
  | ASTVar String

instance Show ASTExpr where
  show (ASTNumber n) = show n
  show (ASTString s) = show s
  show (ASTBool b) = show b
  show (ASTCond es) = "Cond (" ++ unwords (map show es) ++ ")"
  show (ASTLet es e) = "let " ++ unwords (map show es) ++ " in " ++ show e
  show (ASTQuote d) = "quote " ++ show d
  show (ASTLambda args body) = "(" ++ unwords args ++ ") -> " ++ show body
  show (ASTApplication f args) =
    "(" ++ f ++ " " ++ unwords (map show args) ++ ")"
  show (ASTLambdaApplication e args) =
    "(" ++ show e ++ " " ++ unwords (map show args) ++ ")"
  show (ASTVar v) = v

data ASTDef = Define String ASTExpr deriving (Show)

data AST = ASTExpr ASTExpr | ASTDef ASTDef deriving (Show)

endsWith :: String -> String -> Bool
endsWith [] _ = True
endsWith _ [] = False
endsWith x y@(_ : ys) = (x == y) || endsWith x ys

removeLast :: String -> String
removeLast [] = []
removeLast [_] = []
removeLast (x : xs) = x : removeLast xs

createCondArg :: Datum -> Maybe (ASTExpr, ASTExpr)
createCondArg (List [x, y]) = do
  x' <- createASTExpr x
  y' <- createASTExpr y
  return (x', y')
createCondArg _ = Nothing

createCond :: [Datum] -> Maybe ASTExpr
createCond x = mapM createCondArg x <&> ASTCond

createLetArg :: Datum -> Maybe (ASTExpr, ASTExpr)
createLetArg (List [x, y]) = do
  x' <- createASTExpr x
  y' <- createASTExpr y
  return (x', y')
createLetArg _ = Nothing

createLet :: [Datum] -> Maybe ASTExpr
createLet [List x, y@(List _)] = do
  formals <- mapM createLetArg x
  expr <- createASTExpr y
  return $ ASTLet formals expr
createLet _ = Nothing

createLambda :: [Datum] -> Maybe ASTExpr
createLambda [List x, y@(List _)] = do
  formals <- mapM (\(Atom s) -> return s) x
  exp <- createASTExpr y
  return $ ASTLambda formals exp
createLambda _ = Nothing

-- This is gonna be ugly
createDefine :: [Datum] -> Maybe ASTDef
createDefine [List (name : args), body] = do
  name' <- createASTExpr name
  expr' <- createLambda [List args, body]
  return $ Define (show name') expr'
createDefine [name, expr] = do
  name' <- createASTExpr name
  expr' <- createASTExpr expr
  return $ Define (show name') expr'
createDefine _ = Nothing

createASTExpr :: Datum -> Maybe ASTExpr
createASTExpr (List [Atom "quote", d]) = Just $ ASTQuote d
createASTExpr (Atom "#t") = Just $ ASTBool True
createASTExpr (Atom "#f") = Just $ ASTBool False
createASTExpr (Atom ('"' : xs)) =
  if endsWith "\"" xs
    then Just . ASTString $ removeLast xs
    else Nothing
createASTExpr (Atom x) = Just $ ASTVar x
createASTExpr (LitNumber x) = Just $ ASTNumber x
createASTExpr (List (Atom "cond" : s)) = createCond s
createASTExpr (List (Atom "let" : s)) = createLet s
createASTExpr (List (Atom "lambda" : s)) = createLambda s
createASTExpr (List (List (Atom "lambda" : s) : s')) = do
  lb <- createLambda s
  exp <- mapM createASTExpr s'
  return $ ASTLambdaApplication lb exp
createASTExpr (List (Atom func : args)) =
  mapM createASTExpr args >>= Just . ASTApplication func
createASTExpr _ = Nothing

createAST :: Datum -> Maybe AST
createAST (List [x]) = createAST x
createAST r@(List (Atom "define" : s)) = ASTDef <$> createDefine s
createAST r = ASTExpr <$> createASTExpr r

createASTs :: NonEmpty Datum -> Maybe (NonEmpty AST)
createASTs = mapM createAST
