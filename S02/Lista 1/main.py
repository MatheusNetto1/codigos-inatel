import threading
import time
import random
from pymongo import MongoClient

connector = MongoClient("mongodb://localhost:27017")
database = connector['bancoiot']
collection = database.sensores

#print(connector)
#print(database)
#print(collection)

sensores = [
    {"nomeSensor": "Sensor 1", "valorSensor": None, "unidade": "°C", "sensorAlarmado": False},
    {"nomeSensor": "Sensor 2", "valorSensor": None, "unidade": "°C", "sensorAlarmado": False},
    {"nomeSensor": "Sensor 3", "valorSensor": None, "unidade": "°C", "sensorAlarmado": False},
]

for sensor in sensores:
    collection.insert_one(sensor)
 
result = collection.update_many(
    {},
    {
        "$set": {
            "valorSensor": 30,
            "sensorAlarmado": False
        }
    }
)

def monitorar_sensor(sensor_id, intervalo):
    sensor_doc = collection.find_one({"nomeSensor": f"Sensor {sensor_id}"})
    
    while not sensor_doc["sensorAlarmado"]:
        temperatura = round(random.uniform(30, 40),2)
        print(f"Sensor {sensor_id}: {temperatura:.2f}°C")

        collection.update_one(
            {"nomeSensor": f"Sensor {sensor_id}"},
            {"$set": {"valorSensor": temperatura}}
        )

        if temperatura > 38:
            collection.update_one(
                {"nomeSensor": f"Sensor {sensor_id}"},
                {"$set": {"sensorAlarmado": True}}
            )
            print(f"Atenção! Temperatura muito alta! Verificar Sensor {sensor_id}")
            break
        
        time.sleep(intervalo)
        sensor_doc = collection.find_one({"nomeSensor": f"Sensor {sensor_id}"})

t1 = threading.Thread(target = monitorar_sensor, args = (1, 5))
t2 = threading.Thread(target = monitorar_sensor, args = (2, 3))
t3 = threading.Thread(target = monitorar_sensor, args = (3, 7))

t1.start()
t2.start()
t3.start()

t1.join()
t2.join()
t3.join()

print("Monitoramento finalizado.")