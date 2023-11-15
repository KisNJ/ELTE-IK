module Homework4 where

password :: [Char] -> [Char]
password s = replicate (length s) '*'

filterIncPairs :: Ord a => [(a,a)] -> [(a,a)]
filterIncPairs pairs = [(a,b) | (a,b) <- pairs, a < b]

headTail :: [a] -> (a, [a])
headTail list = (head list, tail list)

doubleHead:: [a] -> [b] -> (a,b)
doubleHead a b = (head a, head b)

changeHead :: [a] -> a -> [a]
changeHead (x:xs) s = s:xs

pi' :: Double
pi' = 4 * sum(take 1000 [1 / x | x <- zipWith (*) (cycle [1, -1]) [1,3 ..]])

combinationsBool3 :: [[Bool]]
combinationsBool3 = [[a,b,c] | a <- [True, False], b <- [True, False], c <- [True,False] ]

permutationsWith :: [Bool] -> Int -> [[Bool]]
permutationsWith kapottLista l 
			 | l == length kapottLista = kapottLista : []
permutationsWith kapottLista l = (permutationsWith (kapottLista ++ [True]) l) ++ (permutationsWith (kapottLista ++ [False]) l)

combinationsBool :: Int -> [[Bool]]
combinationsBool n = permutationsWith [True] n ++ permutationsWith [False] n

combinations :: Int -> [a] -> [[a]]
combinations 0 _ = [[]]
combinations len elems = [e:xs | e <- elems, xs <- combinations (len-1) elems]
