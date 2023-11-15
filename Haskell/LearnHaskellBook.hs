module LearnHaskellBook where
import Data.Char
import qualified Data.Map as Map

doubleme x = x + x
doubleUs x y = doubleme x + doubleme y
doubleifsmall x = if x > 100
then x
else x * 2

lostNumbers = [4,8,12,15]

firstLetter :: String -> String
firstLetter "" = "Empty"
firstLetter (x:xs) = xs ++ "of is " ++[x]

replicate' :: Int -> a -> [a]
replicate' n s
   | n <= 0 = []
   | otherwise = s:replicate'(n-1)  s

take' :: Int -> [a] -> [a]
take' num _ | num <= 0 = []
take' _ [] = []
take' num (s:xs) = s:take' (num-1) xs

elem' :: Ord a => a -> [a] -> Bool
elem' _ [] = False
elem' val list
   | val == head list = True
   | otherwise = elem' val (tail list)

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
   let smallerOrEqual = [a | a <- xs, a <= x]
       larger = [a | a <- xs, a > x]
   in quicksort smallerOrEqual ++ [x] ++ quicksort larger

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (a:as) (b:bs) = f a b : zipWith' f as bs

applyTwice :: (a->a) -> a -> a
applyTwice f x = f (f x)

flip' :: (a->b->c) -> b -> a -> c
flip' f x y = f y x

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f x : map' f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs)
   | f x = x : filter' f xs
   | otherwise = filter' f xs

quicksort' :: Ord a => [a] -> [a]
quicksort' [] = []
quicksort' (pivot:xs) = 
   let lesstThanEqTo x = filter (<= x) xs
       greaterThan x = filter (> x) xs
   in  quicksort' (lesstThanEqTo pivot) ++ [pivot] ++ quicksort' (greaterThan pivot)

largestDiv :: Integer
largestDiv = head (filter p [100000,99999 ..1])
            where p x = x `mod` 3829 == 0 

takeWhile' :: (a->Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f (x:xs)
   | f x = x : takeWhile' f xs
   | otherwise = []

oddSumLe10000 :: Integer
oddSumLe10000 = sum $ takeWhile (<10000) $ filter (odd) $ map (^2) [1..]

chain :: Integer -> [Integer]
chain 1 = [1]
chain x
   | even x = x : chain (x `div` 2)
   | odd x = x : chain (3 * x + 1)

longChains :: Int
longChains = length (filter long ( map chain [1..100]))
                where long x = length x > 15

sum' :: Num a => [a] -> a
-- sum' xs = foldl (\acc x -> acc + x) 0 xs
sum' = foldl (+) 0

elem'' :: Eq a => a -> [a] -> Bool
elem'' x xs = foldl (\acc y -> if y == x then True else acc) False xs 

reverse' :: [a] -> [a] 
reverse' xs = foldl (\acc x -> x : acc) [] xs
-- reverse' = foldl (flip (:)) []

product' :: Num a => [a] -> a
product' = foldl ((*)) 1

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' p = foldr (\x acc -> if p x then x:acc else acc) [] 

encode word shift = map (chr . (shift+) . ord) word

sumOfDigits :: Int -> Int
sumOfDigits = sum . map digitToInt . show

phoneStringtoInt :: String -> [Int]
phoneStringtoInt = map digitToInt . filter isDigit
phoneBook :: Map.Map String String
phoneBook = Map.fromList $
   [
      ("betty", "555-2938"),
      ("bonnie", "452-2928"),
      ("patsy", "493-2928"),
      ("lucille", "205-2928"),
      ("wendy", "939-8282"),
      ("penny", "853-2492")
   ]

phoneBookFromList :: (Ord k) => [(k,String)] -> Map.Map k [String]
-- phoneBookFromList xs = Map.fromListWith (++) $ map (\(k, v) -> (k , [v])) xs
phoneBookFromList xs = Map.fromListWith add $ map (\ (k,v) -> (k, [v])) xs
   where add x y = x ++ y

data Car = Car {
   company :: String,
   model :: String,
   year :: Int
} deriving (Show, Read)

data Vector a = Vector a a a deriving Show
data Tree a = EmptyTree | Node a (Tree a) (Tree a)
   deriving (Show)

singleton :: a -> Tree a
singleton a = Node a EmptyTree EmptyTree

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert a EmptyTree = singleton a
treeInsert a (Node val left right) 
   | a == val = Node a left right
   | a < val = Node val (treeInsert a left) right
   | a > val = Node val left (treeInsert a right)
