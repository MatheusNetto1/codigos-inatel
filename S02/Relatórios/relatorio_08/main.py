from database import Database
from central_database import CentrallDatabase

# cria uma instância da classe Database, passando os dados de conexão com o banco de dados Neo4j
db = Database("bolt://18.212.171.122", "neo4j", "chaplain-races-exhaust")
db.drop_all()

central_db = CentrallDatabase(db)

central_db.create_player("Zico")
central_db.create_player("Adriano")
central_db.create_player("Petkovic")
central_db.create_player("Gabigol")

central_db.create_match(1,"Zico")
central_db.create_match(2,"Adriano")
central_db.create_match(3,"Zico")
central_db.create_match(4,"Petkovic")

central_db.insert_player_match("Zico",1)
central_db.insert_player_match("Adriano",2)
central_db.insert_player_match("Adriano",3)
central_db.insert_player_match("Zico",3)
central_db.insert_player_match("Petkovic",4)
central_db.insert_player_match("Petkovic",2)
central_db.insert_player_match("Zico",4)

central_db.get_match_by_id(3)
central_db.get_player_history("Zico")

print("Jogadores: ")
print(central_db.get_players())
print("Partidas: ")
print(central_db.get_matches())

central_db.delete_player("Gabigol")
central_db.delete_match(4)

# Fechando a conexão com o banco de dados
db.close()