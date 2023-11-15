module Homework1 where

-- Int expr
intExpr1 :: Int
intExpr1 = max 5 9

intExpr2 :: Int
intExpr2 = mod 56 13

intExpr3 :: Int
intExpr3 = div 35 7

-- Bool expr
boolExpr1 :: Bool
boolExpr1 = 5 > 2

boolExpr2 :: Bool
boolExpr2 = True && False

boolExpr3 :: Bool
boolExpr3 =  3 * 3 == max 9 6

-- Seven
inc :: Int -> Int
inc x = x + 1

double :: Int -> Int
double x = 2 * x

seven1 :: Int
seven1 = inc(double(inc(inc(inc(0)))))

seven2 :: Int
seven2 = inc(inc(inc(inc(inc(inc(inc((0))))))))

seven3 :: Int
seven3 = inc(inc(inc(double(double(inc(0))))))

-- Lucky number
isLuckyNumber :: Int -> Bool
isLuckyNumber x
    | x == 13 || mod x 2 == 0 || mod x 13 /= 0 = False
    | otherwise = True

-- Leap year
isLeapYear :: Int -> Bool
isLeapYear x
    | mod x 4 /= 0 = False
    | mod x 100 == 0 && mod x 400 /= 0 = False
    | otherwise = True
