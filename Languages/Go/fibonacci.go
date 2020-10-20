package main

import "fmt"

func main() {

	var n int
	fmt.Print("Enter the number of digits to print: ")
	fmt.Scanf("%d", &n)

	var a, b, c int64
    a = 0;
    b = 1;
	n -= 2;

	fmt.Printf("%d %d ",a ,b)
	for n > 0 {
		n--

		c = a + b
		fmt.Printf("%d ", c)
		a = b
		b = c
	}
	fmt.Print("\r\n")

}
