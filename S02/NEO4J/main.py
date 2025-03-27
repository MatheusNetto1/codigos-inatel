from neo4j import GraphDatabase
from neo4j.exceptions import ServiceUnavailable

def buscar_advogados(tx):
    query = """
        MATCH (p:Pessoa:Advogado)
        RETURN p.nome AS nome
    """
    try:
        result = tx.run(query)
        return [row['nome'] for row in result]

    except ServiceUnavailable as exception:
        print(f"{query} raised an error: \n {exception}")
        raise

def buscar_filhos(tx, nome_pessoa):
    query = """
        MATCH (p:Pessoa {nome: $nome_pessoa})-[:PAI_DE]->(filho)
        RETURN filho.nome AS nome
    """
    try:
        result = tx.run(query, nome_pessoa=nome_pessoa)
        return [row['nome'] for row in result]

    except ServiceUnavailable as exception:
        print(f"{query} raised an error: \n {exception}")
        raise

def verificar_namoro(tx, nome1, nome2):
    query = """
        MATCH (p1:Pessoa {nome: $nome1})-[rel:NAMORADO_DE]->(p2:Pessoa {nome: $nome2})
        RETURN rel.desde AS desde
    """
    try:
        result = tx.run(query, nome1=nome1, nome2=nome2)
        record = result.single()
        if record:
            return record['desde']
        else:
            return None

    except ServiceUnavailable as exception:
        print(f"{query} raised an error: \n {exception}")
        raise

uri = "----"
user = "neo4j"
password = "-----"

driver = GraphDatabase.driver(uri, auth=(user, password))

with driver.session() as session:
    advogados = session.execute_read(buscar_advogados)
    print("Advogados:", advogados)

    nome_pessoa = input("Digite o nome da pessoa para verificar os filhos: ")
    filhos = session.execute_read(buscar_filhos, nome_pessoa)
    print(f"{nome_pessoa} é pai/mãe de:", filhos)

    nome1 = input("Digite o nome da primeira pessoa: ")
    nome2 = input("Digite o nome da segunda pessoa: ")
    desde_quando = session.execute_read(verificar_namoro, nome1, nome2)
    
    if desde_quando:
        print(f"{nome1} namora {nome2} desde {desde_quando}.")
    else:
        print(f"{nome1} e {nome2} não estão namorando.")

driver.close()