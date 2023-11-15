module Homework2 where

oneTrue :: Bool -> Bool -> Bool -> Bool
oneTrue True False False = True
oneTrue False True False = True
oneTrue False False True = True
oneTrue _ _ _ = False

isGray :: (Int, Int, Int) -> Bool
isGray (x, y, z)
	| x == 0 && y == 0 && z == 0 = False
	| x == 255 && y == 255 && z == 255 = False
	| x == y && y == z = True
	| otherwise = False

splitQuadruple :: (a,b,c,d) -> ((a,b),(c,d))
splitQuadruple (a, b, c, d) = ((a, b), (c, d))
