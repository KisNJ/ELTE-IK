module Homework where

numbers1 :: [Int]
numbers1 = [x | x <- [1000, 999 .. 0], mod x 5 == 3, mod (x * 3) 7 == 2]

numbers2 :: [Int]
numbers2 = [(div x 2) | x <- [0 .. 500], even x, mod x 7 == 3, mod (x * 2) 6 == 2]

numbers3 :: [Int]
numbers3 = [x | x <- [1 .. 100], mod x 3 == 0 || mod x 5 == 0, mod x 15 /= 0, even x] 

sumOfDivisorsLessThan :: Int -> Int
sumOfDivisorsLessThan x = sum [y | y <- [1 .. x - 1], mod x y == 0 ] 

areAmicableNumbers :: Int -> Int -> Bool
areAmicableNumbers x y
	| sumOfDivisorsLessThan x == y && sumOfDivisorsLessThan y == x = True
	| otherwise = False

test :: [(Int, Int)]
test = [(x, y) | x <- [1..5], y <- [5..6], even x]
