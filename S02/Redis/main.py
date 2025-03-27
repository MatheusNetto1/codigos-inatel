import redis
import os
from time import sleep
import datetime 

redis_conn = redis.Redis (
    host = 'localhost',
    port = 6379,
    decode_responses = True
)

def exibir():
    while(True):
        msgs = []
        msg_key = redis_conn.keys("mensagem:*")
        for m in msg_key:
            msgs.append(redis_conn.hgetall(m))
        
        msgs = sorted(msgs, key=lambda m: m['ts'])
        for m in msgs:
            u = m["remetente"]
            val = m["content"]
            ts = m["ts"]

            if u:
                print(
                    ts,
                    redis_conn.hget(u, "name"),
                    ">> ",
                    val
                )
            sleep(3)

redis_conn.hset("user:1", mapping={
    "name": "Fulano 1",
    "email": "ful1@gmai.com"
})

redis_conn.hset("user:2", mapping={
    "name": "Fulano 2",
    "email": "ful2@gmai.com"
})

redis_conn.hset("mensagem:1", mapping={
    "hora": "00h00",
    "data": "00/00/0000",
    "content": "conteudo 1",
    "remetente": "Fulano 1",
    "destinatario": "Fulano 2"
})