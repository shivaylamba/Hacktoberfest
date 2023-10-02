package main

import "fmt"

func findprimes(number int) bool {
	for i := 2; i < number; i++ {
        if number % i == 0 {
			return false
        }
    }

	if number > 1 {
		return true
	} else {
	    return false
	}
}

func main() {
    fmt.Println("Prime numbers less than 20:")

    for number := 2; number <= 20; number++ {
        if findprimes(number) {
            fmt.Printf("%v ", number)
        }
    }
}