module Homework6 where

import Data.Char

hash :: String -> Integer
hash str = sum [i * 2 ^ ord(ch) | (ch, i) <- zip str [1..]]

caesarEncrypt :: String -> Int -> String
caesarEncrypt "" _ = ""
caesarEncrypt (x:xs) n = val (pushChar x n) : caesarEncrypt xs n
    where val v
            | v > 122 = val (v - 122 + 96)
            | otherwise = chr(v)
          pushChar c m = ord c + m

listDiff :: Eq a => [a] -> [a] -> [a]
listDiff [] _ = []
listDiff (x:xs) s
    | not (x `elem` s) = x : listDiff xs s
    | otherwise = listDiff xs s

validGame :: String -> Bool
validGame game = check (words game)
    where
        check (x:y:xs)
            | last x == head y = check (y:xs)
            | otherwise = False
        check (x:[]) = True
