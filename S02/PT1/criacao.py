from datetime import datetime
from neo4j import GraphDatabase
from neo4j.exceptions import ServiceUnavailable

def limpar_dados(tx):
    try:
        tx.run("MATCH(n) DETACH DELETE n;")
    except:
        print("Erro ao excluir...")
        raise

def criar_familia(tx):
    # Query para criação dos nós e relacionamentos
    # Criei propositalmente relacionamentos de dois tipos (DONO_DE e DONA_DE por exemplo) de modo que eu consiga mostar mais exemplos de consultas. Mas está correto se você fez apenas um tipo de relacionamento.
    query = '''
    CREATE 
        (tobi:Pet:Cachorro{nome:"Tobi",sexo:"M",idade:5}),
        (zetsu:Pet:Gato{nome:"Zetsu",sexo:"M",idade:1}),

        (du:Pessoa:Estudante{nome:"José Eduardo Santos Pereira",sexo:"M",idade:21}),
        (vi:Pessoa:Militar{nome:"Maria Vitória Santos Pereira",sexo:"F",idade:28}),
        (rita:Pessoa:Militar{nome:"Rita de Cássia Junqueira Faustino",sexo:"F",idade:31}),
        
        (pereira:Pessoa:Policial{nome:"Joaquim Silva Pereira", sexo:"M", idade: 55}),
        (ana:Pessoa:Artista{nome:"Ana Moreira Santos", sexo:"F", idade: 51}),
        
        (silva:Pessoa:Militar:Aposentado{nome:"Sebastião Silva", sexo:"M", idade: 76}),
        (justina:Pessoa:Militar:Aposentado{nome:"Justina Pereira", sexo:"F", idade: 71}),

        (dede:Pessoa:Artista{nome:"Adenor Moreira", sexo:"M", idade: 69}),
        (ge:Pessoa:Artista{nome:"Geruza Santos", sexo:"F", idade: 68}),

        (du)-[:DONO_DE]->(tobi),
        (vi)-[:DONA_DE]->(zetsu),

        (du)-[:IRMAO_DE]->(vi),
        (vi)-[:IRMA_DE]->(du),

        (vi)-[:NAMORADA_DE{desde:2018}]->(rita),
        (rita)-[:NAMORADA_DE{desde:2018}]->(vi),

        (pereira)-[:MARIDO_DE{desde:1994}]->(ana),
        (ana)-[:ESPOSA_DE{desde:1994}]->(pereira),

        (du)-[:FILHO_DE]->(pereira),
        (du)-[:FILHO_DE]->(ana),
        (vi)-[:FILHA_DE]->(pereira),
        (vi)-[:FILHA_DE]->(ana),
        (pereira)-[:PAI_DE]->(du),
        (pereira)-[:PAI_DE]->(vi),
        (ana)-[:MAE_DE]->(du),
        (ana)-[:MAE_DE]->(vi),

        (silva)-[:MARIDO_DE{desde:1969}]->(justina),
        (justina)-[:ESPOSA_DE{desde:1969}]->(silva),

        (pereira)-[:FILHO_DE]->(silva),
        (pereira)-[:FILHO_DE]->(justina),
        (silva)-[:PAI_DE]->(pereira),
        (justina)-[:MAE_DE]->(pereira),

        (silva)-[:AVO_DE]->(du),
        (justina)-[:AVO_DE]->(du),
        (silva)-[:AVO_DE]->(vi),
        (justina)-[:AVO_DE]->(vi),
        
        (du)-[:NETO_DE]->(silva),
        (du)-[:NETO_DE]->(justina),
        (vi)-[:NETA_DE]->(silva),
        (vi)-[:NETA_DE]->(justina),


        (dede)-[:MARIDO_DE{desde:1971}]->(ge),
        (ge)-[:ESPOSA_DE{desde:1971}]->(dede),

        (ana)-[:FILHO_DE]->(dede),
        (ana)-[:FILHO_DE]->(ge),
        (dede)-[:PAI_DE]->(ana),
        (ge)-[:MAE_DE]->(ana),

        (dede)-[:AVO_DE]->(du),
        (ge)-[:AVO_DE]->(du),
        (dede)-[:AVO_DE]->(vi),
        (ge)-[:AVO_DE]->(vi),
        
        (du)-[:NETO_DE]->(dede),
        (du)-[:NETO_DE]->(ge),
        (vi)-[:NETA_DE]->(dede),
        (vi)-[:NETA_DE]->(ge)
    RETURN du;
    '''    
    try:
        result = tx.run(query)
        return [{
            'nome': row['du']['nome']
        } for row in result]

    except ServiceUnavailable as exception:

        print("{query} raised an error: \n {exception}".format(query=query, exception=exception))

        raise

def get_militares(tx):
    query = """
        MATCH (n:Militar) RETURN DISTINCT(n.nome) AS militar;
    """
    try:
        result = tx.run(query)
        return [{
            'militar':row['militar']
        } for row in result]

    except ServiceUnavailable as exception:

        print("{query} raised an error: \n {exception}".format(query=query, exception=exception))

        raise

def get_quantos_filhos_filhas(tx, nome):
    query = """
        MATCH (m:Pessoa{nome:$nome})<-[r]-()
        WHERE type(r) IN ["FILHA_DE", "FILHO_DE"]
        RETURN COUNT(r) as filhos_filhas;
    """
    try:
        result = tx.run(query, nome=nome)
        return [{
            'filhos_filhas':row['filhos_filhas']
        } for row in result]

    except ServiceUnavailable as exception:

        print("{query} raised an error: \n {exception}".format(query=query, exception=exception))

        raise

def get_ano_inicio_relacionamentos(tx):
    query = """
        MATCH (n:Pessoa)-[r]->(m:Pessoa)
        WHERE r.desde IS NOT NULL
        RETURN DISTINCT(n.nome) AS pessoa1, type(r) AS tipo_relacionamento, m.nome AS pessoa2, r.desde AS ano
    """

    try:
        result = tx.run(query)
        return [{
            'pessoa1': row['pessoa1'],
            'pessoa2': row['pessoa2'],
            'tipo_relacionamento': row['tipo_relacionamento'],
            'ano': row['ano']
        } for row in result]

    except ServiceUnavailable as exception:

        print("{query} raised an error: \n {exception}".format(query=query, exception=exception))

        raise

def main():
    uri = "neo4j+s://44e5f47e.databases.neo4j.io"
    user = "neo4j"
    password = "fm43QGz1sprFdg4kaNNjrGVD-g7A4ig33pvhArDSLlU"

    driver = GraphDatabase.driver(uri, auth=(user, password))

    print("Limpando dados...")
    with driver.session() as session:
        session.execute_write(limpar_dados)

    print("Criando a família...")
    with driver.session() as session:
        result = session.execute_write(criar_familia)

        if len(result):

            print(f"Família de {result[0]['nome']} criada.")
        else:
            print("Erro ao criar família")
            driver.close()
            return
            

    print("----- Pessoas que são militares -----")
    with driver.session() as session:
        result = session.execute_read(get_militares)
        for i in result:
            print(i['militar'])

    print("----- Total de filhos(as) de uma determinada pessoa -----")
    nome = input("Digite o nome da pessoa:")
    with driver.session() as session:
        result = session.execute_read(get_quantos_filhos_filhas, nome)
        quantidade = result[0]['filhos_filhas']
        if quantidade > 0:
            print(quantidade)
        else:
            print(quantidade)
            print("Essa pessoa não tem filhos(as).")

    print("----- Duração dos relacionamentos na família -----")
    ano = datetime.now().year
    with driver.session() as session:
        result = session.execute_read(get_ano_inicio_relacionamentos)
        for i in result:
            print(f"{i['pessoa1']} é {i['tipo_relacionamento']} {i['pessoa2']} por aproximadamente {ano - int(i['ano'])} ano(s).")


    driver.close()

if __name__ == "__main__":
    main()

