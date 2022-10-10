from difflib import SequenceMatcher

with open("1.txt") as f1, open("2.txt") as f2:
    f1Data = f1.read()
    f2Data = f2.read()
    similarity = SequenceMaster(None, f1Data, f2Data).ratio()
    print(similarity*100)
