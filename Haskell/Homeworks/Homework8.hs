module Homework8 where

data T = A String Int | B String Int | C
f :: [T] -> Int
f (_:_:B _ 1:_)            = 0
f (_:_:B [] _:[])          = 1
f (_:A [_] _:B [] _:[xs])  = 2
f (_:A _ _:B _ _:xs)       = 3

g = [C, A "A" 2, B "" 4, C]

triangleArea :: (Double, Double, Double) -> Maybe Double
triangleArea (x, y, z) |
    x <= 0 || y <= 0 || z <= 0 = Nothing
triangleArea (x, y, z) |
    x^2 + y^2 == z^2 && x + y > z && x + z > y && y + z > x = Just (x * y / 2)
triangleArea _ = Nothing

data Storage = HDD String Int Int | SSD String Int
    deriving (Eq, Show)

largestSSD :: [Storage] -> Maybe Storage
largestSSD xs = maxStorage [ssd | ssd@(SSD _ _) <- xs]
                where 
                maxStorage [] = Nothing
                maxStorage  xs = Just $ foldl1 (\maxSSD@(SSD _ maxStorage) ssd@(SSD _ storage) -> if storage > maxStorage then ssd else maxSSD) xs

hugeHDDs :: [Storage] -> [Storage]
hugeHDDs xs = hugeHDD [hdd | hdd@(HDD _ _ _) <- xs] (largestSSD xs)
    where 
        hugeHDD [] _ = []
        hugeHDD hdds (Just (SSD _ storageSSD)) = filter (\hdd@(HDD _ _ storage) -> storage > storageSSD) hdds
