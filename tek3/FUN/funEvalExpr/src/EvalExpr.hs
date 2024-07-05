module EvalExpr
  ( launchProg,
  )
where

import GHC.IO.Exception (ExitCode (ExitSuccess))
import Jaarse (Expression (..), Parser (runParser), expr)
import System.Exit (ExitCode (ExitFailure), exitSuccess, exitWith)
import Text.Printf (printf)

maybeDiv :: Maybe Float -> Maybe Float -> Maybe Float
maybeDiv Nothing _ = Nothing
maybeDiv _ Nothing = Nothing
maybeDiv _ (Just 0) = Nothing
maybeDiv (Just x) (Just y) = return $ x / y

maybeAdd :: Maybe Float -> Maybe Float -> Maybe Float
maybeAdd Nothing _ = Nothing
maybeAdd _ Nothing = Nothing
maybeAdd (Just x) (Just y) = return $ x + y

maybeSub :: Maybe Float -> Maybe Float -> Maybe Float
maybeSub Nothing _ = Nothing
maybeSub _ Nothing = Nothing
maybeSub (Just x) (Just y) = return $ x - y

maybeMul :: Maybe Float -> Maybe Float -> Maybe Float
maybeMul Nothing _ = Nothing
maybeMul _ Nothing = Nothing
maybeMul (Just x) (Just y) = return $ x * y

maybePow :: Maybe Float -> Maybe Float -> Maybe Float
maybePow Nothing _ = Nothing
maybePow _ Nothing = Nothing
maybePow (Just x) (Just y) = return $ y ** x -- This is swapped for a reason :)

eval :: Expression -> Maybe Float
eval (Num n) = Just n
eval (Add x y) = maybeAdd (eval x) (eval y)
eval (Sub x y) = maybeSub (eval x) (eval y)
eval (Mul x y) = maybeMul (eval x) (eval y)
eval (Div x y) = maybeDiv (eval x) (eval y)
eval (Pow x y) = maybePow (eval x) (eval y)

getRes :: Maybe (Expression, String) -> Maybe Float
getRes Nothing = Nothing
getRes (Just (e, "")) = eval e
getRes _ = Nothing

parseExpr :: String -> Maybe (Expression, String)
parseExpr [] = Nothing
parseExpr a = runParser expr a

displayResult :: Maybe Float -> IO Int
displayResult Nothing = putStrLn "Parsing error" >> return 84
displayResult (Just 0) = printf "0.00\n" >> return 0
displayResult (Just x) = printf "%.2f\n" x >> return 0

launchProg :: Maybe String -> IO ()
launchProg (Just expr) = do
  res <- displayResult $ getRes $ parseExpr expr
  case res of
    0 -> exitSuccess
    _ -> exitWith (ExitFailure 84)
launchProg Nothing = putStrLn "Argument error"
