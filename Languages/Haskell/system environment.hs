import System.Environment

main = do
    getArgs >>= print
    getProgName >>= print
    getEnvironment >>= print