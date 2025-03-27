class Animal {
  constructor(nome, idade, especie) {
    this.nome = nome
    this.idade = idade
    this.especie = especie
  }
  
  printInfo() {
    console.log(`Nome: ${this.nome}`)
    console.log(`Idade: ${this.idade}`)
    console.log(`Espécie: ${this.especie}`)
  }
}

class Cachorro extends Animal {
  #raca
  constructor(nome, idade, especie, raca) {
    super(nome, idade, especie)
    this.#raca = raca
  }
  
  printInfo() {
    super.printInfo()
    console.log(`Raça: ${this.#raca}`)
  }
}

class Gato extends Animal {
  #cores = []
  constructor(nome, idade, especie, cores) {
    super(nome, idade, especie)
    this.#cores = cores
  }
  printInfo() {
    super.printInfo()
    console.log(`Cor(es): ${this.#cores.join(', ')}`)
  }
}

let animal = new Animal('Nome do Animal', 5, 'Especie do Animal')
let cachorro = new Cachorro('Nome do Cachorro', 3, 'Especie do Cachorro', 'Raca do Cachorro')
let gato = new Gato('Nome do Gato', 2, 'Especie do Gato', ['Cor 1', 'Cor 2', 'Cor 3'])

animal.printInfo()
console.log('----------------------')
cachorro.printInfo()
console.log('----------------------')
gato.printInfo()