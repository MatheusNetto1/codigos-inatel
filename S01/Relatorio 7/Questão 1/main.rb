puts "\t\t--- Menu ---"
print "Entre com o primeiro número: "
num1 = gets.chomp.to_i
print "Entre com o segundo número: "
num2 = gets.chomp.to_i
print "Entre com o terceiro número: "
num3 = gets.chomp.to_i

media = (num1 + num2 + num3) / 3.0

puts "--- Números digitados ---"
puts "Primeiro número: #{num1}"
puts "Segundo número: #{num2}"
puts "Terceiro número: #{num3}"

puts "\tMédia: #{media.round(2)}"