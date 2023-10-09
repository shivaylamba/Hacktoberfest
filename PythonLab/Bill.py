

curr = int(input("Enter Current  Bill Amount :-"))
prev = int(input("Enter  Previous Bill Amount :-"))
bill = 0
if prev<=curr:
    read = curr-prev
    if read <=100:
        bill = curr*5 -(prev*5)
        
    if read <= 200:
        bill = 500
        t = read-100
        bill = bill + t*10
       
    else:
        bill = 1500
        t = read-200
        bill = bill + t*20

    print("Bill Reading:-", read, " \nBill Amount :-", bill)

else:
    print("Invalid Bill Amount")