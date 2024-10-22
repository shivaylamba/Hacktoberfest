import wikipedia as wiki # Import the library

topic = input("Please enter the topic: ")
results = wiki.search(topic) # Search for related articles
print("[+] Found", len(results), "entries!")
print("Select the article: ")
for index, value in enumerate(results): # Give the user an opportunity to choose between the articles
	print(str(index)+ ")"+" "+str(value))

print("\n")
article = int(input())
try: # Try retrieving info from the Wiki page
	page = wiki.page(results[article])
	print(str(page.title).center(1000))
	print(page.url)
	print(wiki.summary(results[article], sentences=1))
except DisambiguationError as e: # Workaround for the disambiguation error
	print("[-] An error occured!")
	print("URL: "+"https://en.wikipedia.org/wiki/"+str(results[article]).replace(' ', '_'))