import requests
from bs4 import BeautifulSoup

# Send a GET request to the website
url = "https://example.com"  # Replace with the URL of the website you want to scrape
response = requests.get(url)

# Check if the request was successful
if response.status_code == 200:
    # Create a BeautifulSoup object and specify the parser
    soup = BeautifulSoup(response.text, 'html.parser')

    # Extract specific elements from the HTML
    # Example: Get all the links on the page
    links = soup.find_all('a')

    # Print the extracted links
    for link in links:
        print(link.get('href'))
else:
    print("Failed to retrieve the webpage.")
