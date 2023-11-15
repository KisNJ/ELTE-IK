module Homework7 where

data RPS = Rock | Paper | Scissors
	deriving (Show, Eq)

firstPlayerWon :: [(RPS, RPS)] -> Int
firstPlayerWon [] = 0
firstPlayerWon (x:xs) = wonGame x + firstPlayerWon xs
	where 
		wonGame (Rock, Scissors) = 1
		wonGame (Paper, Rock) = 1
		wonGame (Scissors, Paper) = 1
		wonGame _ = 0

data Vector3 = V Int Int Int
	deriving (Show, Eq)

crossProduct :: Vector3 -> Vector3 -> Vector3
crossProduct (V a b c) (V x y z) = (V (b*z - c*y) (c*x - a*z) (a*y - b*x))

vectorListSum :: [Vector3] -> Vector3
vectorListSum ((V a b c):(V x y z):xs) = vectorListSum (V (a+x) (b+y) (c+z):xs)
vectorListSum [x] = x
vectorListSum [] = V 0 0 0

data Temperature = Night Int | Daytime Int
    deriving (Show, Eq)

extremes :: [Temperature] -> (Int, Int)
extremes temps = (maximum days, minimum nights)
	where 
		days = [x | Daytime x <- temps]
		nights = [x | Night x <- temps]

