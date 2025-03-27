import redis
import os
from time import sleep
from datetime import datetime
import threading

redis_conn = redis.Redis(host="127.0.0.1", port=6379, decode_responses=True)



# exibir as mensagens dos dois usuários
def exibir():
    while(True):
        msgs = []
        msg_keys = redis_conn.keys("mensagem:*")
        for m in msg_keys:
            msgs.append(redis_conn.hgetall(m))

        msgs = sorted(msgs, key=lambda m: m['ts'])
        for m in msgs:

            u = m["remetente"]
            val = m["conteudo"]
            ts = m["ts"]
            if(u):
                print(
                    ts,
                    redis_conn.hget(u, "nome"), 
                    ">> ", 
                    val
                )
        sleep(3)
        os.system('cls' if os.name == 'nt' else 'clear')

x = threading.Thread(target=exibir)
x.start()

# cadastro do usuário 1

redis_conn.hset("usuario:1",  mapping={
    'nome': 'Poles',
    "email": 'poles@g.com'
})
redis_conn.expire("usuario:1", 60)

# cadastro do usuário 2

redis_conn.hset("usuario:2",  mapping={
    'nome': 'Soebad',
    "email": 'ssaliv@g.com'
})
redis_conn.expire("usuario:2", 60)

sleep(2)

# usuário 1 manda uma mensagem

redis_conn.hset(f"mensagem:1", mapping={
    "conteudo": 'Olá Soebad! Alguma novidade?',
    "ts": str(datetime.now()),
    "remetente": "usuario:1",
    "destinatario": "usuario:2"
})
redis_conn.expire("mensagem:1", 10)

sleep(3)

# usuários 2 manda uma mensagem
redis_conn.hset(f"mensagem:2", mapping={
    "conteudo": 'Olá Poles! Nada ainda...',
    "ts": str(datetime.now()),
    "remetente": "usuario:2",
    "destinatario": "usuario:1"
})
redis_conn.expire("mensagem:2", 10)

sleep(3)

# usuário 2 manda uma mensagem

redis_conn.hset(f"mensagem:3", mapping={
    "conteudo": 'Espero que resolvam logo Poles...',
    "ts": str(datetime.now()),
    "remetente": "usuario:2",
    "destinatario": "usuario:1"
})
redis_conn.expire("mensagem:3", 10)

sleep(3)

# usuário 1 manda uma mensagem 

redis_conn.hset(f"mensagem:4", mapping={
    "conteudo": 'Também espero Soebad..',
    "ts": str(datetime.now()),
    "remetente": "usuario:1",
    "destinatario": "usuario:2"
})
redis_conn.expire("mensagem:4", 10)

sleep(3)

# usuário 1 manda uma mensagem

redis_conn.hset(f"mensagem:5", mapping={
    "conteudo": 'Aliás, alguém te informou sobre a próxima reunião Soebad?',
    "ts": str(datetime.now()),
    "remetente": "usuario:1",
    "destinatario": "usuario:2"
})
redis_conn.expire("mensagem:5", 10)

sleep(3)

# usuário 2 manda uma mensagem

redis_conn.hset(f"mensagem:6", mapping={
    "conteudo": 'Será sexta às 19h Poles.',
    "ts": str(datetime.now()),
    "remetente": "usuario:2",
    "destinatario": "usuario:1"
})
redis_conn.expire("mensagem:6", 10)

sleep(3)

# fim
x.join()