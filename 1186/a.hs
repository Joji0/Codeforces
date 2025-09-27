module Main where


main :: IO ()
main = do
    [n, m, k] <- map (read :: String -> Int) . words <$> getLine
    let check = min m k
    if n <= check
        then 
            putStrLn "YES"
        else 
            putStrLn "NO"
