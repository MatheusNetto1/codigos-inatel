from database import Database
from helper.writeAJson import writeAJson
from pokedex import Pokedex

db = Database(database="pokedex", collection="pokemons")
# db.resetDatabase()

pokedex = Pokedex(db)

pokedex.primeiraBusca()
pokedex.segundaBusca()
pokedex.terceiraBusca()
pokedex.quartaBusca()
pokedex.quintaBusca()