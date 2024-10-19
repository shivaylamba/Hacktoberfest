def getEvensFromArray(arr):
    return list(filter(lambda a: a % 2 == 0, arr))


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    print(getEvensFromArray(arr))

    arr2 = [11, 20, 30, 40, 50, 60]
    print(getEvensFromArray(arr2))
