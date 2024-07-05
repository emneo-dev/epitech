module Main where

import Control.Monad
import Data.Functor
import Data.List.NonEmpty (NonEmpty ((:|)))
import HALAbstractSyntaxtTree
import HALEval
import HALParsing
import Jaarse
import System.Environment
import System.Exit
import System.IO

prompt :: String
prompt = "H > "

printEndResult :: Show a => Throws (a, b) -> IO Int
printEndResult (Left e) = putStrLn ("Error: " ++ show e) >> return 84
printEndResult (Right (e, _)) = print e >> return 0

-- This is here to be sure that the prompt is printed before the user inputs
flush :: String -> IO ()
flush a = putStr a >> hFlush stdout

getPrompt :: String -> IO String
getPrompt prompt = flush prompt >> getLine

evaluateMultiple :: Env -> NonEmpty AST -> Throws (RTVal, Env)
evaluateMultiple env (x :| []) = evaluate env x
evaluateMultiple env (x :| (x' : xs)) = do
  (a, env') <- evaluate env x
  evaluateMultiple env' (x' :| xs)

evaluate :: Env -> AST -> Throws (RTVal, Env)
evaluate = eval

evaluateDatums :: Env -> NonEmpty Datum -> Throws (RTVal, Env)
evaluateDatums env d =
  case createASTs d of
    Just r -> evaluateMultiple env r
    Nothing -> throw $ Default "Syntax error"

parseFile :: Env -> String -> IO (Throws (RTVal, Env))
parseFile env file = readFile file <&> parseOneString env

parseOneString :: Env -> String -> Throws (RTVal, Env)
parseOneString env s =
  case runParser exprs s of
    Nothing -> throw ParserError
    Just ([], "") -> throw $ Default "No input"
    Just (a : as, "") -> evaluateDatums env (a :| as)
    _ -> throw ParserError

runRepl :: Env -> IO Int
runRepl env = do
  input <- getPrompt prompt
  case input of
    ":q" -> return 0
    _ -> case parseOneString env input of
      Left e -> print e >> runRepl env
      Right (a, env') -> print a >> runRepl env'

launchMultipleFile :: Env -> [String] -> IO Int
launchMultipleFile env [] = return 0
launchMultipleFile env [x] = parseFile env x >>= printEndResult
launchMultipleFile env (x : xs) = do
  r <- parseFile env x
  case r of
    Left e -> print e >> return 84
    Right (a, env') -> launchMultipleFile env' xs

launch :: [String] -> IO Int
launch [] = runRepl getEmptyEnv
launch f = launchMultipleFile getEmptyEnv f

main :: IO ()
main = do
  args <- getArgs
  exitCode <- launch args
  case exitCode of
    0 -> return ()
    _ -> exitWith $ ExitFailure exitCode
