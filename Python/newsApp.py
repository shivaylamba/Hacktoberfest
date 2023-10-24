import requests
import json

news = input("What type of news do you want to read?: ")
url = f"https://newsapi.org/v2/everything?q={news}&from=2023-08-22&sortBy=publishedAt&apiKey=0c802386dbfa4f958169034c4147e426"
r = requests.get(url)
final = json.loads(r.text)

for i in final["articles"]:
    print(i["title"])
    print(i["description"])
    print(i["url"])
    print("--------------------------")