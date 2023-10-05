package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func takeInputNum(a string) (z1 int64, z2 int64, w1 float64, w2 float64, op string) {
	scanner := bufio.NewScanner(os.Stdin) //scanner object

	if a == "I" {
		fmt.Printf("a :- ")
		scanner.Scan()
		x, _ := strconv.ParseInt(scanner.Text(), 10, 64)

		fmt.Printf("b :- ")
		scanner.Scan()
		y, _ := strconv.ParseInt(scanner.Text(), 10, 64)

		z1 = x
		z2 = y
		w1 = 0
		w2 = 0
	}
	if a == "F" {
		fmt.Printf("a :- ")
		scanner.Scan()
		x, _ := strconv.ParseFloat(scanner.Text(), 64)

		fmt.Printf("b :- ")
		scanner.Scan()
		y, _ := strconv.ParseFloat(scanner.Text(), 64)

		z1 = 0
		z2 = 0
		w1 = x
		w2 = y
	}
	// getting the operation type
	fmt.Printf("Operations (+, -, /, x) :- ")
	scanner.Scan()
	op = scanner.Text()

	return
}

func main() {
	fmt.Println("Welcome to CLI Calculator")
	scanner := bufio.NewScanner(os.Stdin) //scanner object

	for choice := "yes"; choice != "no"; {

		//whether user want to do operation in float or integer
		fmt.Printf("Press I for integer operations or F for decimal operations - ")
		scanner.Scan()

		//integer operation
		if scanner.Text() == "I" {
			a, b, _, _, op := takeInputNum("I")

			//printing out result
			fmt.Printf("Result - ")
			if op == "+" {
				fmt.Printf("%d", a+b)
			} else if op == "-" {
				fmt.Printf("%d", a-b)
			} else if op == "/" {
				fmt.Printf("%d", a/b)
			} else if op == "*" {
				fmt.Printf("%d", a*b)
			}
		} else if scanner.Text() == "F" {
			_, _, a, b, op := takeInputNum("F")

			//printing out result
			fmt.Printf("Result - ")
			if op == "+" {
				fmt.Printf("%f", a+b)
			} else if op == "-" {
				fmt.Printf("%f", a-b)
			} else if op == "/" {
				fmt.Printf("%f", a/b)
			} else if op == "*" {
				fmt.Printf("%f", a*b)
			}
		}

		//continuation decision of loop
		fmt.Printf("\nDo you want to continue (yes/no) ? ")
		scanner.Scan()
		choice = scanner.Text()
	}
}
