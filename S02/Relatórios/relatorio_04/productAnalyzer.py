from database import Database
from helper.writeAJson import writeAJson

class ProductAnalyzer:
    def __init__(self, db: Database):
        self.db = db

    def totalDeVendasPorDia(self):
        result = self.db.collection.aggregate([
            {"$unwind": "$produtos"},
            {"$group": {
                "_id": "$data_compra",
                "total_vendas": {"$sum": 1}
            }},
        ])
        writeAJson(result, "Total de vendas por dia")

    def produtoMaisVendidoEmTodasAsCompras(self):
        result = self.db.collection.aggregate([
            {"$unwind": "$produtos"},
            {"$group": {
                "_id": "$produtos.descricao",
                "quantidade_vendida": {"$sum": "$produtos.quantidade"}
            }},
            {"$sort": {"quantidade_vendida": -1}},
            {"$limit": 1}
        ])
        writeAJson(result, "Produto mais vendido em todas as compras")

    def clienteQueMaisGastouEmUmaCompra(self):
        result = self.db.collection.aggregate([
            {"$unwind": "$produtos"},
            {"$group": {
                "_id": "$cliente_id",
                "total_gasto": {"$sum": {"$multiply": ["$produtos.quantidade", "$produtos.preco"]}}
            }},
            {"$sort": {"total_gasto": -1}},
            {"$limit": 1}
        ])
        writeAJson(result, "Cliente que mais gastou em uma única compra")

    def produtosComQuantidadeVendidaAcimaDeUmaUnidade(self):
        result = self.db.collection.aggregate([
            {"$unwind": "$produtos"},
            {"$group": {
                "_id": "$produtos.descricao",
                "quantidade_vendida": {"$sum": "$produtos.quantidade"}
            }},
            {"$match": {"quantidade_vendida": {"$gt": 1}}},
            {"$sort": {"quantidade_vendida": -1}}
        ])
        writeAJson(result, "Produtos que tiveram uma quantidade vendida acima de 1 unidade")