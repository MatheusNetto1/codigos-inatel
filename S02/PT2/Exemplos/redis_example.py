import redis 

redis_conn = redis.Redis(
    host="127.0.0.1", 
    port=6379,
    decode_responses=True
)

redis_conn.hset("product:1", mapping={
    "nome": "Smartphone",
    "preco": 15987.99,
    "marca": "Apple",
    "descricao": "Um smartphone simples de entrada"
})

redis_conn.hset("product:2", mapping={
    "nome": "Macbook",
    "preco": 12999.99,
    "marca": "Apple",
    "descricao": "Um notebbok simples de entrada"
})
# redis_conn.lrem("estoque", 2,"poduct:1" )
# redis_conn.lrem("estoque", 2,"product:2" )
redis_conn.lpush("estoque", "product:1","product:2")

tamanho_estoque = redis_conn.llen("estoque")

estoque = redis_conn.lrange("estoque", 0, tamanho_estoque-1)
print(estoque)
for produto in estoque:
    print(redis_conn.hget(produto, "nome"))
    print(redis_conn.hget(produto, "preco"))
    print()