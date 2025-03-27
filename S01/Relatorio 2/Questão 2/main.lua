--Exercício 2
A = {}
contadorPar = 0

for i = 1, 100, 1 do
  A[i] = math.random(1, 100)
  if A[i]%2 == 0 then
    contadorPar = contadorPar + 1
  end
end

print(contadorPar)