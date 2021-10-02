A = [[6,20],
    [32 ,2],
    [7 ,8]]

AT = [[0,0,0],
         [0,0,0]]


for i in range(len(A)):
   for j in range(len(A[0])):
       AT[j][i] = A[i][j]

for AT in AT:
   print(AT)
