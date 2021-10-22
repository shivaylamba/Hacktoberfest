n = int(input())
#pascal triangle
a=[]
for i in range(n):
    a.append([])
    a[i].append(1)
    for j in range(1,i):
        s=a[i-1][j-1]+a[i-1][j]
        a[i].append(s)
    a[i].append(1)
for i in range(n):
    print(' '*(n-i-1),end=' ')
    for j in range(0,i+1):
        print(a[i][j],end=' ')
    print(end='\n')




#pascal diamond 
a=[]
for i in range(n):
    a.append([])
    a[i].append(1)
    for j in range(1,i):
        s=a[i-1][j-1]+a[i-1][j]
        a[i].append(s)
    a[i].append(1)
for i in range(n):
    print(' '*(n-i-1),end=' ')
    for j in range(0,i+1):
        print(a[i][j],end=' ')
    print(end='\n')
n=n-1
for i in range(n-1,-1,-1):
    print(' '*(n-i),end=' ')
    for j in range(0,i+1):
        print(a[i][j],end=' ')
    print(end='\n')
