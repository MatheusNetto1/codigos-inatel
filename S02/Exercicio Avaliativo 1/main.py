from database import Database
from motoristaDAO import MotoristaDAO
from cli import MotoristaCLI

db = Database(database="AV1", collection="Motoristas")
motoristaDAO = MotoristaDAO(database=db);


motoristaCLI = MotoristaCLI(motoristaDAO)
motoristaCLI.run()