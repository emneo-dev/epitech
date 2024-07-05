--
-- EPITECH PROJECT, 2021
-- B-FUN-400-TLS-4-1-compressor-pauline.faure
-- File description:
-- main
--

import System.Environment
import System.IO
import Control.Monad
import Data.Char
import Data.Maybe
import Text.Printf
import Text.Read
import System.Exit
import System.Random

data Position = Position
    { x :: Int
    , y :: Int
    } deriving (Eq,Ord,Show)

data Color = Color
    { red :: Int
    , green :: Int
    , blue :: Int
    } deriving (Eq,Ord,Show)

data Cluster = Cluster
    { clusterColor :: Color
    , clusterPixels :: [Pixel]
    , clusterSumColor :: Color
    , clusterNumber :: Int
    } deriving (Eq,Ord,Show)

data Pixel = Pixel
    { pixelPosition :: Position
    , pixelColor :: Color
    } deriving (Eq,Ord,Show)

data Option = Op
    { opHelper :: Bool
    , opClusters :: Int
    , opConvergence :: Double
    , opFile :: String
    } deriving (Eq,Ord,Show)

parsing :: [String] -> Option
parsing [] = Op True 0 0.0 ""
parsing arr = parsingInt arr $ Op False 0 0.0 ""

parsingInt :: [String] -> Option -> Option
parsingInt [] op = op
parsingInt ("-h":_) _ = Op True 0 0.0 ""
parsingInt ("--help":_) _ = Op True 0 0.0 ""
parsingInt [_] _ = Op True 0 0.0 ""
parsingInt ("-n":a:x) (Op h n l f) = parsingInt x $ Op h (read a :: Int) l f
parsingInt ("-l":a:x) (Op h n l f) = parsingInt x $ Op h n (read a :: Double) f
parsingInt ("-f":a:x) (Op h n l f) = parsingInt x $ Op h n l a
parsingInt _ _ = Op True 0 0.0 ""

usage :: IO()
usage = putStrLn "USAGE: ./imageCompressor -n N -l L -f F\n" >>
    putStrLn "\tN\tnumber of colors in the final image" >>
    putStrLn "\tL\tconvergence limit" >>
    putStrLn "\tF\tpath to the file containing the colors of the pixels"

-- The implementation for Nothing is shit but it'll do for now
dispAllClusters :: Maybe [Cluster] -> IO()
dispAllClusters Nothing = print ""
dispAllClusters (Just a) = mapM_ dispCluster a

dispCluster :: Cluster -> IO()
dispCluster cluster = putStrLn "--" >>
    dispColor (clusterColor cluster) >>
    putStrLn "\n-" >>
    mapM_ dispPixel (clusterPixels cluster)

dispPosition :: Position -> IO()
dispPosition pos = printf "(%i,%i)" (x pos) (y pos)

dispColor :: Color -> IO()
dispColor (Color r g b) = printf "(%i,%i,%i)" r g b

dispAllPixels :: [Pixel] -> IO()
dispAllPixels = mapM_ dispPixel

dispPixel :: Pixel -> IO()
dispPixel px = dispPosition (pixelPosition px) >>
    putStr " " >>
    dispColor (pixelColor px) >>
    putStrLn ""

createRandValue :: Int -> IO Int
createRandValue max_value = fst . randomR (0, max_value) <$> newStdGen

-- TODO
createRandCluster :: [Pixel] -> IO Cluster
createRandCluster px = do
    index <- createRandValue $ length px
    let color = pixelColor $ px!!index
    return $ Cluster color [] (Color 0 0 0) 0

isColorEqual :: Cluster -> Pixel -> Bool
isColorEqual (Cluster a _ _ _) (Pixel _ b) = a == b

removeClusterClr :: Cluster -> [Pixel] -> [Pixel]
removeClusterClr _ [] = []
removeClusterClr a (b:bs)
    | isColorEqual a b = removeClusterClr a bs
    | otherwise = b:removeClusterClr a bs

createRandClusters :: Int -> [Cluster] -> Maybe [Pixel] -> IO (Maybe [Cluster])
createRandClusters _ _ Nothing = return Nothing
createRandClusters 0 a _ = return $ Just a
createRandClusters a b (Just px) = do
    cluster <- createRandCluster px
    createRandClusters (a - 1) (cluster:b) $ Just $ removeClusterClr cluster px

getDistClr :: Color -> Color -> Int
getDistClr (Color a b c) (Color d e f) = (d - a) ^ 2 + (e - b) ^ 2 + (f - c) ^ 2

isBestCluster :: Int -> [Int] -> Bool
isBestCluster a b = all (>= a) b

addColors :: Color -> Color -> Color
addColors (Color a b c) (Color d e f) = Color (a + d) (b + e) (c + f)

assignPx :: Pixel -> [Cluster] -> Bool -> [Int] -> [Cluster]
assignPx _ [] _ _= []
assignPx _ a _ [] = a
assignPx a ((Cluster b c _ _):bs) True (dst:rest)
    | isBestCluster dst rest =
        Cluster b (a:c) (Color 0 0 0) 0:bs
    | otherwise = Cluster b c (Color 0 0 0) 0:assignPx a bs True rest
assignPx a ((Cluster d _ b c):bs) False (dst:rest)
    | isBestCluster dst rest =
        Cluster d [] (addColors b (pixelColor a)) (c + 1):bs
    | otherwise = Cluster d [] b c:assignPx a bs False rest

getDstlist :: Color -> [Cluster] -> [Int]
getDstlist a [] = []
getDstlist a ((Cluster b _ _ _):bs) = getDistClr a b:getDstlist a bs

preAssignPx :: Pixel -> [Cluster] -> Bool -> [Cluster]
preAssignPx a b c = assignPx a b c $ getDstlist (pixelColor a) b

assignPxs :: [Pixel] -> [Cluster] -> Bool -> [Cluster]
assignPxs [] c _ = c
assignPxs (a:xs) c update = assignPxs xs (preAssignPx a c update) update

calcDif :: Cluster -> Cluster -> Double
calcDif (Cluster a _ _ _) (Cluster b _ _ _) =
    sqrt $ fromIntegral $ getDistClr a b

-- Old clusters | New clusters | Coefficient
isDone :: [Cluster] -> [Cluster] -> Double -> Bool
isDone [] [] _ = True
isDone (a:as) (b:bs) c =
    let dif = calcDif a b
    in case dif <= c of
        True -> isDone as bs c
        False -> False

quickDiv :: Int -> Int -> Int
quickDiv a b = ceiling $ fromIntegral a / fromIntegral b

getUpdateClr :: Color -> Int -> Color
getUpdateClr (Color a b c) d =
    Color (quickDiv a d) (quickDiv b d) (quickDiv c d)

updateClusterClr :: Cluster -> Cluster
updateClusterClr (Cluster a _ b c) =
    Cluster (getUpdateClr b c) [] (Color 0 0 0) 0
--updateClusterClr (Cluster a b) = Cluster (getPxAvg b) b

updateClustersClr :: [Cluster] -> [Cluster]
updateClustersClr a = updateClusterClr <$> a

doComp :: [Pixel] -> [Cluster] -> Double -> [Cluster]
doComp a b c =
    let clusters = updateClustersClr $ assignPxs a b False
    in case isDone b clusters c of
        True -> assignPxs a clusters True
        False -> doComp a clusters c

-- This is the entry point :o
doCompress :: Maybe [Pixel] -> Maybe [Cluster] -> Double -> Maybe [Cluster]
doCompress Nothing _ _ = Nothing
doCompress _ Nothing _ = Nothing
doCompress (Just a) (Just b) c = return $ doComp a b c

parseFile :: String -> IO(Maybe [Pixel])
parseFile filepath = do
    content <- openFile filepath ReadMode >>= hGetContents
    let pixels = getPixel <$> lines content
    case length pixels of
        0 -> return Nothing
        _ -> return $ sequence pixels

getPixel :: String -> Maybe Pixel
getPixel str = do
    let [firstStr, secondStr] = words str
    pos <- getPos firstStr
    clr <- getColor secondStr
    Just (Pixel pos clr)

-- This took me so long to figure out
getPos :: String -> Maybe Position
getPos str = do
    (xPos, yPos) <- readMaybe str :: Maybe (Int, Int)
    return $ Position xPos yPos

-- Basically the same as getPos
getColor :: String -> Maybe Color
getColor str = do
    (r, g, b) <- readMaybe str :: Maybe (Int, Int, Int)
    return $ Color r g b

launchProg :: Option -> IO Int
launchProg (Op True _ _ _) = usage >> exitWith (ExitFailure 84)
launchProg (Op _ n l f) = do
    pixels <- parseFile f
    clusters <- createRandClusters n [] pixels
    dispAllClusters $ doCompress pixels clusters l
    exitSuccess

main :: IO Int
main = do
    strArgs <- getArgs
    launchProg $ parsing strArgs
