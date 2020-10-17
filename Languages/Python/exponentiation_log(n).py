def exponentiate(x, n):

    if (n == 0):
        return 1
    elif (int(n % 2) == 0):
        return (exponentiate(x, int(n / 2)) *
                exponentiate(x, int(n / 2)))
    else:
        return (x * exponentiate(x, int(n / 2)) *
                exponentiate(x, int(n / 2)))


x = int(input("Enter the value of x - "))
n = int(input("Enter the value of n - "))
print("power(x,n) =", exponentiate(x, n))
