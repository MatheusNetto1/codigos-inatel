from passageiro import Passageiro
from corrida import Corrida
from motorista import Motorista

class SimpleCLI:
    def __init__(self):
        self.commands = {}

    def add_command(self, name, function):
        self.commands[name] = function

    def run(self):
        while True:
            command = input("Enter a command: ")
            if command == "quit":
                print("Goodbye!")
                break
            elif command in self.commands:
                self.commands[command]()
            else:
                print("Invalid command. Try again.")


class MotoristaCLI(SimpleCLI):
    def __init__(self, motorista_model):
        super().__init__()
        self.motorista_model = motorista_model
        self.add_command("create", self.create_motorista)
        self.add_command("read", self.read_motorista)
        self.add_command("update", self.update_motorista)
        self.add_command("delete", self.delete_motorista)

    def create_motorista(self):
        corridas = []
        while True:
            nome_passageiro = input("Entre com o nome do passageiro: ")
            documento_passageiro = input("Entre com o documento do passageiro: ")
            passageiro = Passageiro(nome_passageiro, documento_passageiro)

            nota_corrida = int(input("Entre com a nota da corrida: "))
            distancia = float(input("Entre com a distância da corrida: "))
            valor = float(input("Entre com o valor da corrida: "))

            corrida = Corrida(nota_corrida, distancia, valor, vars(passageiro))
            corridas.append(vars(corrida))

            mais_corridas = input("Deseja adicionar mais corridas? (s/n): ")
            if mais_corridas.lower() != 's':
                break
        
        nota_motorista = int(input("Entre com a nota do motorista: "))

        motorista = Motorista(nota_motorista, corridas)
    
        self.motorista_model.create_motorista(motorista)
        
    def read_motorista(self):
        id = input("Enter the id: ")
        motorista = self.motorista_model.read_motorista_by_id(id)

        if motorista:
            print("Corridas:")
            for corrida in motorista.get('corridas', []):
                print(f"Nota da corrida: {corrida['nota']}")
                print(f"Distância: {corrida['distancia']}")
                print(f"Valor: {corrida['valor']}")

                print("\nPassageiros: ")

                passageiro = corrida['passageiro']
                print(f"Nome do passageiro: {passageiro['nome']}")
                print(f"Documento do passageiro: {passageiro['documento']}")
            
            print(f"Nota do motorista: {motorista.get('nota')}")

    def update_motorista(self):
        id = input("Enter the id: ")
        nome_passageiro = input("Entre com o novo nome do passageiro: ")
        documento_passageiro = input("Entre com o novo documento do passageiro: ")

        passageiro = Passageiro(nome_passageiro, documento_passageiro)

        corridas = []
        while True:
            nota_corrida = int(input("Entre com a nova nota da corrida: "))
            distancia = float(input("Entre com a nova distância da corrida: "))
            valor = float(input("Entre com o novo valor da corrida: "))

            corrida = Corrida(nota_corrida, distancia, valor, vars(passageiro))
            corridas.append(vars(corrida))

            mais_corridas = input("Deseja adicionar mais corridas? (s/n): ")
            if mais_corridas.lower() != 's':
                break

        nota_motorista = int(input("Entre com a nova nota do motorista: "))

        novo_motorista = Motorista(nota_motorista, corridas)

        self.motorista_model.update_motorista(id, novo_motorista)

    def delete_motorista(self):
        id = input("Enter the id: ")
        self.motorista_model.delete_motorista(id)

    def run(self):
        print("Welcome to the motorista CLI!")
        print("Available commands: create, read, update, delete, quit")
        super().run()