package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Print("Enter the number of digits to print: ")
	fmt.Scanf("%d", &n)

	if n <= 0 {
		fmt.Println("Invalid input. Please enter a positive number.")
		return
	}

	// Edge case: Print first Fibonacci number if n is 1
	if n >= 1 {
		fmt.Printf("0 ")
	}
	if n >= 2 {
		fmt.Printf("1 ")
	}

	// Array to store Fibonacci numbers
	fib := make([]int64, n)
	fib[0] = 0
	fib[1] = 1

	for i := 2; i < n; i++ {
		fib[i] = fib[i-1] + fib[i-2]
	}

	// Print the Fibonacci sequence
	for i := 2; i < n; i++ {
		fmt.Printf("%d ", fib[i])
	}
	fmt.Println()
}
