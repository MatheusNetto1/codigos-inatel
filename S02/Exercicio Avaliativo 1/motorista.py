from corrida import Corrida
from typing import List

class Motorista:
    def __init__(self, nota: int, corridas: list[Corrida]):
        self.nota = nota
        self.corridas = corridas