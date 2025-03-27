from database import Database

class Query:
    def __init__(self, database):
        self.db = database

    def result(query_function):
        data = query_function()
        if data:
            for d in data:
                print(d)
            else:
                print("Nenhum resultado encontrado!")

    def find_Renzo(self): # Questão 1 - a. ------------------------------
        query = "MATCH (t:Teacher {name: $name}) RETURN t.ano_nasc, t.cpf"
        parameters = {"name": "Renzo"}
        result(self.db.execute_query(query, parameters))

    def find_teacher_M(self): # Questão 1 - b. ------------------------------
        query = "MATCH (t:Teacher) WHERE t.name STARTS WITH 'M' RETURN t.name, t.cpf"
        result(self.db.execute_query(query))

    def find_all_cities(self): # Questão 1 - c. ------------------------------
        query = "MATCH (c:City) RETURN c.name"
        result(self.db.execute_query(query))
    
    def find_number_school(self): # Questão 1 - d. ------------------------------
        query = "MATCH (s:School) WHERE s.number >= 150 AND s.number <= 550 RETURN s.name, s.address, s.number"
        result(self.db.execute_query(query))

    def find_youngest_date(db): # Questão 2 - a. ------------------------------
        query = "MATCH (t:Teacher) RETURN MIN(t.ano_nasc), MAX(t.ano_nasc)"
        result(self.db.execute_query(query))

    def find_AVG(self): # Questão 2 - b. ------------------------------
        query = "MATCH (c:City) RETURN AVG(c.population)"
        result(self.db.execute_query(query))

    def find_CEP(self): # Questão 2 - c. ------------------------------
        query = "MATCH (c:City) WHERE c.cep = '37540-000' RETURN REPLACE(c.name, 'a', 'A')"
        result(self.db.execute_query(query))

    def teachers_third_letter(self): # Questão 2 - d. ------------------------------
        query = "MATCH (t:Teacher) RETURN substring(t.name, 2, 1)"
        result(self.db.execute_query(query))

    def show_results(self):
        find_Renzo()
        find_teacher_M()
        find_all_cities()
        find_youngest_date()
        find_AVG()
        find_CEP()
        teachers_third_letter()
        self.db.close()