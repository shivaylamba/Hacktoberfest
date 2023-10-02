package main

import "fmt"

func main() {
    val := 0
    for{
		fmt.Println("Enter a number:\n")
		fmt.Scanf("%d",&val)

		switch{
		case val < 0:
			panic("You entered negative number!!!")
		case val ==  0:
			fmt.Println("0 is neither negative nor positive")
		default:
			fmt.Println("You have entered:\t",val)
		}


	}

}