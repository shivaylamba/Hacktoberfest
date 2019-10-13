import random
import functools
import operator
import math

arr = list(map(int, input().split()))

points = []

print(arr)

while arr:
    n = arr[0]
    r = random.randint(1,256)

    # eq: f(x) = n + r*x
    print("eq : f(x) = {} + {}x".format(n,r))
    pointsArr = []
    for i in range(1, 5):
        f = ( n + (r*i) )
        p = (i, f)
        pointsArr.append(p)

    points.append(pointsArr)
    arr.pop(0)

print(points)
print(arr)

while points:
    a = points[0]
    p = random.sample(a,2)
    d = {}
    X = {}
    Y = {}
    for i in range(2):
        d["p{}".format(i)] = p[i]
        X["x{}".format(i)] = d["p{}".format(i)][0]
        Y["y{}".format(i)] = d["p{}".format(i)][1]
    
    r = 0
    prod = functools.reduce(operator.mul, X.values(), 1) 
    
    for i in range(2):
        s = Y["y{}".format(i)] * ((-(prod/X["x{}".format(i)]))/(X["x{}".format(i)] - (sum(X.values())-X["x{}".format(i)])))
        r += math.ceil(s)
    
    print(p)
    print(d)
    print(X)
    print(Y)
    
    arr.append(r)
    
    points.pop(0)

print(points)
print(arr)
