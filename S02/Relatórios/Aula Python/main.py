from pymongo import MongoClient

connector = MongoClient("mongodb://localhost:27017")

database = connector['countries']

collection = database.country

result = collection.find(
    {"region": "Europe", "area": {"$gt": 300_000} },
    {"name": 1}
)

result = result.sort("capital", -1)

for r in result:
    print(r)