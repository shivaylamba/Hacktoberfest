def spiral(mat):
    r = len(mat)
    c = len(mat[0])
    k = 0
    l = 0

    while(k<r-1 and l<c-1):
        for i in range(l,c):
            print(mat[k][i])
        k+=1

        for i in range(k,r):
            print(mat[i][r])
        c-=1

        if(r>k):
            for i in range(c-1,l-1,-1):
                print(mat[r-1][i])
            r-=1

        if(c>l):
            for i in range(r-1,k-1,-1):
                print(mat[i][l])
            l+=1


matrix = [[1,2,3,4,5],
          [2,3,4,5,6],
          [3,4,5,6,7],
          [4,5,6,7,8]]

spiral(matrix)