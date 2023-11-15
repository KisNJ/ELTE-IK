module Homework where

toBin :: Integer -> [Int]
toBin 0 = []
toBin n = fromIntegral n `mod` 2 : toBin (n `div` 2)

remdup :: Eq a => [a] -> [a]
remdup [] = []
remdup [a] = [a]
remdup (x:y:xs)
    | x == y = remdup (y:xs)
    | otherwise = x: remdup (y:xs)

keepIncreasingTriples :: Ord a => [(a,a,a)] -> [(a,a,a)]
keepIncreasingTriples [] = []
keepIncreasingTriples (t@(a,b,c):xs)
    | a < b && b < c = t:keepIncreasingTriples xs
    | otherwise = keepIncreasingTriples xs

deleteEveryThird :: [a] -> [a]
deleteEveryThird (a:b:c:xs) = a:b:deleteEveryThird xs
deleteEveryThird list
    | length list < 3 = list

alternate :: [a] -> [a] -> [a]
alternate [] [] = []
alternate [x] [y] = [x]
alternate (x:xx:xs) (y:yy:ys) = x:yy:(alternate xs ys)
