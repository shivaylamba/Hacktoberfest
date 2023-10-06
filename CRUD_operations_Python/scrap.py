from selenium import webdriver 
from bs4 import BeautifulSoup 
import pandas as pd #install chrom webdriver 
#webdriver can be downloaded from 
#https://sites.google.com/chromium.org/driver/downloads/versionselection?authuser=0
driver = webdriver.Chrome(executable_path='G:\Program Files\Anaconda3\chromdriver\chromedriver.exe') 
products=[] #List to store name of the product 
prices=[] #List to store price of the product 
ratings=[] #List to store rating of the product 
driver.get("https://www.flipkart.com/gaminglaptopsstore?otracker=nmenu_sub_Electronics_0_Gaming%20Laptops&otracker=nmenu_sub_Electr onics_0_Gaming%20Laptops") 
content = driver.page_source 
soup = BeautifulSoup(content) 
# print(soup) 
for a in soup.findAll('div',attrs={'class':'_37K3-p'}):
 print (a) 
 name=a.find('a', attrs={'class':'s1Q9rs'}) 
 price=a.find('div',attrs={'class':'_30jeq3'}) 
 rating=a.find('div',attrs={'class':'_3LWZlK'}) 
 products.append(name.text) 
 prices.append(price.text)
 ratings.append(rating.text) 
df = pd.DataFrame({'Product Name':products,'Price':prices,'Rating':ratings}) 
df.to_csv('products.csv', index=False, encoding='utf-8')
