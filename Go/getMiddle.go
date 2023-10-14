package main

import (
	"fmt"
)

func GetMiddle(s string) {
	//Code goes here!
	result := ""

	if len(s)%2 == 0 {
		result += string(s[len(s)/2-1])
		result += string(s[len(s)/2])

	} else {
		result += string(s[len(s)/2])
	}

	fmt.Println(result)
}
