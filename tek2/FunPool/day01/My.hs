mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x >= 0 = x
        | otherwise = -x

myMin :: Int -> Int -> Int
myMin a b | a < b = a
          | otherwise = b

myMax :: Int -> Int -> Int
myMax a b | a > b = a
          | otherwise = b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "Empty list"
myHead (xs:_) = xs

myTail :: [a] -> [a]
myTail [] = error "Empty list"
myTail (_:xs) = xs

myLength :: [a] -> Int
myLength [] = 0
myLength xs = 1 + myLength (myTail xs)

myNth :: [a] -> Int -> a
myNth [] b = error "Index too large"
myNth a 0 = myHead a
myNth a b
        | b < 0 = error "Negative Index"
        | otherwise = myNth (myTail a) (b - 1)

myTake :: Int -> [a] -> [a]
myTake a [] = []
myTake 0 b = []
myTake 1 b = [myHead b]
myTake a [b] = [b]
myTake a (b:c)
        | a <= 0 = []
        | otherwise = b:myTake (a - 1) c

myDrop :: Int -> [a] -> [a]
myDrop a [] = []
myDrop a b
        | a <= 0 = b
        | otherwise = myDrop (a - 1) (myTail b)

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend a b = myHead a:myAppend (myTail a) b

myInit :: [a] ->  [a]
myInit [] = error "Empty list bro"
myInit a = myReverse (myTail (myReverse a))

myLast :: [a] -> a
myLast [] = error "Empty list"
myLast [a] = a
myLast a = myLast (myTail a)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:x) = myAppend (myReverse x) [a]

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip a b = myAppend [(myHead a, myHead b)] (myZip (myTail a) (myTail b))

myUnzipLeft :: [(a, b)] -> [a]
myUnzipLeft [] = []
myUnzipLeft ((x, y): xs) = x:myUnzipLeft xs

myUnzipRight :: [(a, b)] -> [b]
myUnzipRight [] = []
myUnzipRight ((x, y): xs) = y:myUnzipRight xs

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x:myUnzipLeft xs, y:myUnzipRight xs)

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap a (b:xs) = a b:myMap a xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter a (b:xs)
        | a b = b:myFilter a xs
        | otherwise = myFilter a xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ b [] = b
myFoldl f b (a:xs) = myFoldl f (f b a) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr f b (a:xs) = f a (myFoldr f b xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f a = (myFilter f a, myFilter (not . f) a)

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (a:xs) = let (b, c) = myPartition (f a) xs
        in myAppend (myAppend (myQuickSort f c) [a]) (myQuickSort f b)