class Sales:
    def _init_(self):
        self.cost_opt = 0
        self.a = [[0 for _ in range(100)] for _ in range(100)]
        self.visit = [0] * 100

    def mincost_opt(self, city, n):
        self.visit[city] = 1
        print(city, "-->", end=" ")
        ncity = self.least_opt(city, n)
        if ncity == 999:
            ncity = 1
            print(ncity)
            self.cost_opt += self.a[city][ncity]
            return
        self.mincost_opt(ncity, n)

    def least_opt(self, c, n):
        nc = 999
        min_val = 999
        kmin = 999
        for i in range(1, n + 1):
            if self.a[c][i] != 0 and self.visit[i] == 0:
                if self.a[c][i] < min_val:
                    min_val = self.a[i][1] + self.a[c][i]
                    kmin = self.a[c][i]
                    nc = i
        if min_val != 999:
            self.cost_opt += kmin
        return nc


def main():
    x = Sales()
    n = int(input("Enter number of cities: "))
    print("Enter the cost matrix:")
    for i in range(1, n + 1):
        row = list(map(int, input().split()))
        for j in range(1, n + 1):
            x.a[i][j] = row[j - 1]
        x.visit[i] = 0

    print("The cost matrix is:")
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(x.a[i][j], end="\t")
        print()

    print("Optimal solution:")
    print("The path is:")
    x.mincost_opt(1, n)
    print("Minimum cost is", x.cost_opt)


if __name__ == "__main__":
    main()

    
