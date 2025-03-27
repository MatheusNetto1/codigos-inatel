from database import Database
from helper.writeAJson import writeAJson
from productAnalyzer import ProductAnalyzer

db = Database(database="mercado", collection="compras")
#db.resetDatabase()

analyzer = ProductAnalyzer(db)

analyzer.totalDeVendasPorDia()
analyzer.produtoMaisVendidoEmTodasAsCompras()
analyzer.clienteQueMaisGastouEmUmaCompra()
analyzer.produtosComQuantidadeVendidaAcimaDeUmaUnidade()