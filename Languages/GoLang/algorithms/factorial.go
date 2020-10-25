package main

import "fmt"

func factorial(num int) int {
	if num == 0 {
		return 1
	}
	return num * factorial(num-1)
}

func main() {
	fmt.Printf("Factorial of %d is: %d\n", 1, factorial(1))
	fmt.Printf("Factorial of %d is: %d\n", 2, factorial(2))
	fmt.Printf("Factorial of %d is: %d\n", 3, factorial(3))
	fmt.Printf("Factorial of %d is: %d\n", 4, factorial(4))
	fmt.Printf("Factorial of %d is: %d\n", 5, factorial(5))
}
