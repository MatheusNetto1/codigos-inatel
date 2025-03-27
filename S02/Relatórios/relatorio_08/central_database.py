class CentrallDatabase:
    def __init__(self, database):
        self.db = database

    def create_player(self, name):
        query = "CREATE (:Player {name: $name})"
        parameters = {"name": name}
        self.db.execute_query(query, parameters)

    def create_match(self, match_id, winner_name):
        query = """
                CREATE (m:Match {id: $match_id, winner: $winner_name})
                """
        parameters = {"match_id": match_id, "winner_name": winner_name}
        self.db.execute_query(query, parameters)

    def get_players(self):
        query = "MATCH (p:Player) RETURN p.name AS name"
        results = self.db.execute_query(query)
        return [result["name"] for result in results]

    def get_match_by_id(self, match_id):
        query = """
                MATCH (m:Match {id: $match_id})<-[:Participa]-(p:Player)
                RETURN p.name AS player_name, m.id AS match_id, m.winner AS winner
                """
        parameters = {"match_id": match_id}
        results = self.db.execute_query(query, parameters)
        return [(result["player_name"], result["match_id"], result["winner"]) for result in results]

    
    def update_player(self, old_name, new_name):
        query = "MATCH (p:Player {name: $old_name}) SET p.name = $new_name"
        parameters = {"old_name": old_name, "new_name": new_name}
        self.db.execute_query(query, parameters)
        
    def update_match_winner(self, match_id, new_winner_name):
        query = "MATCH (m:Match {id: $match_id}) SET m.winner = $new_winner_name"
        parameters = {"match_id": match_id, "new_winner_name": new_winner_name}
        self.db.execute_query(query, parameters)

    def insert_player_match(self, player_name, match_id):
        query = "MATCH (p:Player {name: $player_name}) MATCH (m:Match {id: $match_id}) CREATE (p)-[:Participa]->(m)"
        parameters = {"player_name": player_name, "match_id": match_id}
        self.db.execute_query(query, parameters)

    def delete_player(self, name):
        query = "MATCH (p:Player {name: $name}) DETACH DELETE p"
        parameters = {"name": name}
        self.db.execute_query(query, parameters)
    
    def delete_match(self, match_id):
        query = "MATCH (m:Match {id: $match_id}) DETACH DELETE m"
        parameters = {"match_id": match_id}
        self.db.execute_query(query, parameters)

    def get_player_history(self, player_name):
        query = """
                MATCH (p:Player {name: $player_name})-[:Participa]->(m:Match)
                RETURN m.id AS match_id, m.winner AS winner
                """
        parameters = {"player_name": player_name}
        results = self.db.execute_query(query, parameters)
        return [(result["match_id"], result["winner"]) for result in results]