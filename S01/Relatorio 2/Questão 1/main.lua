--Exercício 1
print("Digite um número: ")
x = io.read()
x = tonumber(x)

print("Tabuada de " .. x)
for i = 0, 10, 1 do
  print(x .. " x " .. i .. " = " .. i*x)
end