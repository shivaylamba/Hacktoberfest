status=input().upper()
cless=input()
amt=float(input())
hr_before_dep=int(input())
if(cless=="1A"):
    clk=240
elif(cless=="2A"):
    clk=200
elif(cless=="3A"):
    clk=180
elif(cless=="CC"):
    clk=180
elif(cless=="SL"):
    clk=120
elif(cless=="2S"):
    clk=60

if(status=="WL"or status=="RAC"):
    fee=60;
elif(status=="CNF"):
    if(hr_before_dep>48):
        fee=clk;
    elif(hr_before_dep<=48 and hr_before_dep>12):
        fee=amt*25/100
        if(fee<clk):
            fee=clk;
    elif(hr_before_dep<=12 and hr_before_dep>4):
        fee=amt*50/100
        if(fee<clk):
            fee=clk
    elif(hr_before_dep<4):
        fee=amt;
print("The cancellation fee is:",fee)

