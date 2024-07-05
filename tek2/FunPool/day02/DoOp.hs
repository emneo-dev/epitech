myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem a (x:xs)
    | a == x = True
    | otherwise = myElem a xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a b = Just (div a b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] b = Nothing
safeNth a 0 = Just (head a)
safeNth a b
        | b < 0 = Nothing
        | otherwise = safeNth (tail a) (b - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc a = a >>= \b -> Just (b + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup a (b:xs)
    | a == fst b = Just (snd b)
    | otherwise = myLookup a xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo f (Just a) (Just b) = Just (f a b)

isInt :: [Char] -> Bool
isInt a = case reads a :: [(Int, String)] of
    [(_, "")] -> True
    _         -> False

readInt :: [Char] -> Maybe Int
readInt a
    | isInt a = Just (read a)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength a = putStrLn a >>
    return (length a)

printChars :: Char -> Int -> IO ()
printChars _ 0 = return ()
printChars a b = putChar a >>
    printChars a (b - 1)

printBody :: Int -> Int -> IO ()
printBody _ 0 = return ()
printBody _ (-1) = return ()
printBody a b = putChar '|' >>
    printChars ' ' (a - 2) >>
    putStrLn "|" >>
    printBody a (b - 1)

printHead :: Int -> Int -> IO ()
printHead _ 0 = return ()
printHead a _ = putChar '+' >>
    printChars '-' (a - 2) >>
    putStrLn "+"

printBox :: Int -> IO ()
printBox a
    | a > 0 = printHead (a * 2) a >>
        printBody (a * 2) (a - 2) >>
        printHead (a * 2) (a - 1)
    | otherwise = return ()

concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines a = do
    line <- getLine
    next <- concatLines (a - 1)
    return (line ++ next)

getInt :: IO (Maybe Int)
getInt = getLine >>= \b -> return (readInt b)