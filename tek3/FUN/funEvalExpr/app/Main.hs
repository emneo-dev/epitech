module Main where

import EvalExpr ( launchProg )
import System.Environment (getArgs)
import System.Exit (exitWith)

parseArgs :: [String] -> Maybe String
parseArgs [a] = Just a
parseArgs _ = Nothing

main :: IO ()
main = do
    args <- getArgs
    launchProg $ parseArgs args
