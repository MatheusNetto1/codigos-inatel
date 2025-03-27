from database import Database
from teacher_crud import TeacherCrud
from query import Query

db = Database("----", "neo4j", "-----")

# Questões 1 e 2
query_db = Query(db)
query_db.show_results()

# Questão 3
teacher_db = TeacherCrud(db)
teacher_db.create('Chris Lima',1956,'189.052.396-66')
print(teacher_db.read("Chris Lima"))
teacher_db.update("Chris Lima","162.052.777-77")