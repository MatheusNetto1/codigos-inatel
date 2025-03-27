class Carro
  attr_accessor :modelo, :ano
  def initialize(modelo, ano)
    @modelo = modelo
    @ano = ano
  end

  def descrever
    puts "Tipo do carro: Não especificado!"
    puts "O carro é um #{@modelo} do ano #{@ano}"
    puts "--------------"
  end
end

class CarroSedan < Carro
  def descrever
    puts "Tipo do carro: Sedan!"
    puts "O carro é um #{@modelo} do ano #{@ano}"
    puts "--------------"
  end
end

class CarroEsportivo < Carro
  def descrever
    puts "Tipo do carro: Esportivo!"
    puts "O carro é um #{@modelo} do ano #{@ano}"
    puts "--------------"
  end
end

carro = Carro.new("Jeep Compass", 2023)
carroSedan = CarroSedan.new("Toyota Corolla", 2022)
carroEsportivo = CarroEsportivo.new("Ferrari 488 GTB", 2020)

carro.descrever
carroSedan.descrever
carroEsportivo.descrever