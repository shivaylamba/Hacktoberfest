a=int(input())
for i in range (a):
    k=1
    k1=1
    i1=1
    i=10
    it=10
    sum1=1
    a=int(input ())
    while a!=k:
        if k>1000:
            k=int(k/1000)
            k=k+1
            i1=1
            i=it
            i=i + 10
            it=it+10
            k1=k1+1
            print(k,sum1,"in")
            sum1=sum1 + k1*i1
            print(k,sum1,"in")
            continue
        k=k+i
        i=i*10
        i1=i1+1
        print(k,sum1,"1st")
        sum1=sum1 + k1*i1
        print(k,sum1,"2nd")
    print(sum1)
