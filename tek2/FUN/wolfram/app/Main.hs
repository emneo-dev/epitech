module Main where

import System.Exit ( ExitCode(ExitFailure), exitWith, exitSuccess )
import System.Environment ( getArgs )
import System.IO ()
import Text.Read ( readMaybe )

data Option = Op
    { opRule :: Int
    , opLines :: Int
    , opStart :: Int
    , opMove :: Int
    , opWindow :: Int
    } deriving (Eq,Ord,Show)

data MaybeOption = OpM
    { opMRule :: Maybe Int
    , opMLines :: Maybe Int
    , opMStart :: Maybe Int
    , opMMove :: Maybe Int
    , opMWindow :: Maybe Int
    } deriving (Eq,Ord,Show)

convertToChar :: Int -> Char
convertToChar 1 = '*'
convertToChar _ = ' '

-- Yes I did that, it is way easier like this
-- Basically is all about the length of the string
-- (Because i can't go infinite)
magicNum :: Int
magicNum = 10000

-- the last line should never be used but smh the linter :/
calcRule :: Int -> Char -> Char -> Char -> Char
calcRule a '*' '*' '*' = convertToChar $ (a `div` 128) `mod` 2
calcRule a '*' '*' ' ' = convertToChar $ (a `div` 64) `mod` 2
calcRule a '*' ' ' '*' = convertToChar $ (a `div` 32) `mod` 2
calcRule a '*' ' ' ' ' = convertToChar $ (a `div` 16) `mod` 2
calcRule a ' ' '*' '*' = convertToChar $ (a `div` 8) `mod` 2
calcRule a ' ' '*' ' ' = convertToChar $ (a `div` 4) `mod` 2
calcRule a ' ' ' ' '*' = convertToChar $ (a `div` 2) `mod` 2
calcRule a ' ' ' ' ' ' = convertToChar $ a `mod` 2
calcRule _ _ _ _ = ' '

parsing :: [String] -> Maybe MaybeOption
parsing [] = Nothing
parsing arr = do
    parsed <- parsingInt arr $ Just $ OpM (Just (-1))
        (Just (-1)) (Just 0) (Just 0) (Just 80)
    Just parsed

getDispLine :: String -> Int -> Int -> String
getDispLine _ 0 _ = ""
getDispLine "" _ _ = ""
getDispLine (a:as) w 0 = a:getDispLine as (w - 1) 0
getDispLine (a:as) w n = getDispLine as w (n - 1)

trimString :: String -> Int -> Int -> String
trimString _ _ 0 = []
trimString (s : xs) 0 w = s : trimString xs 0 (w - 1)
trimString (s : xs) n w = trimString xs (n - 1) w

-- I hate this so much but I don't have much idea how to refactor it :/
getFirstLine :: Option -> String
getFirstLine (Op _ _ _ move window) =
    case window `mod` 2 == 1 of
        False ->
            concat (replicate (window `div` 2 + move + magicNum) " ")
            ++ "*" ++
            concat (replicate (window `div` 2 + move + magicNum - 1) " ")
        True ->
            concat (replicate ((window - 1) `div` 2 + move + magicNum) " ")
            ++ "*" ++
            concat (replicate ((window - 1) `div` 2 + move + magicNum) " ")

-- Linter here is complaining but the forgotten pattern is never used
getNewLine :: String -> Int -> String
getNewLine [a,b] rule = [calcRule rule a b ' ']
getNewLine (a:b:c:as) rule = calcRule rule a b c:getNewLine (b:c:as) rule

parsingInt :: [String] -> Maybe MaybeOption -> Maybe MaybeOption
parsingInt [] op = op
parsingInt [_] _ = Nothing
parsingInt ("--rule":a:x) (Just (OpM _ n l f d)) =
    parsingInt x $ Just $ OpM (readMaybe a :: Maybe Int) n l f d
parsingInt ("--lines":a:x) (Just (OpM h _ l f d)) =
    parsingInt x $ Just $ OpM h (readMaybe a :: Maybe Int) l f d
parsingInt ("--start":a:x) (Just (OpM h n _ f d)) =
    parsingInt x $ Just $ OpM h n (readMaybe a :: Maybe Int) f d
parsingInt ("--move":a:x) (Just (OpM h n l _ d)) =
    parsingInt x $ Just $ OpM h n l (readMaybe a :: Maybe Int) d
parsingInt ("--window":a:x) (Just (OpM h n l f _)) =
    parsingInt x $ Just $ OpM h n l f (readMaybe a :: Maybe Int)
parsingInt _ _ = Nothing

usage :: IO()
usage = putStrLn "USAGE: ./wolfram --rule N [--lines --start --move --window]"

progLoop :: Option -> String -> IO()
progLoop (Op _ 0 _ _ _) _ = return ()
progLoop (Op rule lines 0 move window) line =
    putStrLn (getDispLine line window magicNum) >>
    progLoop (Op rule (lines - 1) 0 move window) (getNewLine (' ':line) rule)
progLoop (Op rule lines start move window) line =
    putStrLn (getDispLine line window magicNum) >>
    progLoop (Op rule lines (start-1) move window) (getNewLine (' ':line) rule)

launchProg :: Maybe Option -> IO Int
launchProg Nothing = usage >> exitWith (ExitFailure 84)
launchProg (Just a) = progLoop a (getFirstLine a) >> exitSuccess

checkArgs :: Maybe MaybeOption -> Maybe Option
checkArgs (Just (OpM (Just r) (Just l) (Just s) (Just m) (Just w))) =
    case r >= 0 && r <= 255 && s >= 0 && w >= 0 && l >= 0 of
        True -> Just $ Op r l s m w
        False -> Nothing
checkArgs _ = Nothing

main :: IO Int
main = do
    strArgs <- getArgs
    launchProg $ checkArgs $ parsing strArgs
