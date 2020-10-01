import urllib

def read_text() :
    text = "Hello This is a text to check the profanity of the sentence"
    text2 = "This is a sentence having a profane word SHIT"
    
    profanity_checker(text)
    profanity_checker(text2)
    
def profanity_checker(text) :
    connection = urllib.urlopen("http://www.wdylike.appspot.com/?q="+text)
    output = connection.read()
    
    if output == "true":
        print("\nProfanity Alert !! for \'"+text+"\'")
    elif output == "false":
        print("\nNo Cuss Words :) in \'"+text+"\'")
        
read_text()