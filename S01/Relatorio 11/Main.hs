module Main where

-- Exercício 1
lista = [30,29..1]
func = last(reverse(map(*3) lista))

-- Exercício 2
fat :: Int -> Int
fat n
    | n == 0 = 1
    | n > 0 = n * fat (n - 1)
    | otherwise = n * 2

main = do
    print(func)
    numero <- getLine
    print(fat(read numero :: Int))

-- Por algum motivo tive problema com o Storage do Replit, logo que eu criava o Repl do Haskell a memória batia o limite de 2 GiB na plataforma (antes de criar eu ainda tinha outros dois repls, somando a memória dos dois n dava nem 0.18 GiB)
-- Então eu fiz o código no VS Code mas sem um compilador, então não consegui testar o código