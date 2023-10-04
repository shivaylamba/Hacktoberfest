// Using Recursion with Memoization:
#include <iostream>
#include <vector>

std::vector<int> memo;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    memo.resize(n + 1, -1); // Initialize memoization array

    std::cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }

    return 0;
}
