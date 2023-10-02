package main

import (
	"fmt"
	"strconv"	
	"os"
	"math/rand"
	"time"

)
import "regexp"
func main(){
	var name string = "Vilas"
	fmt.Println("Hello", name)
	var myAge = 22
	fmt.Println(myAge)
	weight := 75
	fmt.Println(weight)


	// declaring constant variable which can't be changes
	const HttpStatus = 200

	const(	
		StatusOk = 0
		statusError = 1
		StatusReset = 2
	)

	// default values 
	var defInt int 
	fmt.Println(defInt)
	var defBool bool 
	fmt.Println(defBool)

	i, _ := strconv.Atoi("-45") // we are not going to use the value of _ variable and we can't ignore that also, code gives an error
	s := strconv.Itoa(-45)
	fmt.Println(i,s)

	//taking inputs from command line args
	cmdInp1, _ := strconv.Atoi(os.Args[1])
	cmdInp2, _ := strconv.Atoi(os.Args[2]) 

	fmt.Println("Sum: ",cmdInp1 + cmdInp2)

	//calling custom function
	fmt.Println("Multiplication: ",mult(os.Args[1],os.Args[2]))
	fmt.Println("Division: ",divn(os.Args[1],os.Args[2]))

	val1, val2 := calc(cmdInp1,cmdInp2)
	fmt.Println("Mod: ",val1,"Sub: ",val2)
	val1, _ = calc(cmdInp1,cmdInp2)// we can discard return values
	fmt.Println("Mod: ",val1)
	
	// call by ref
	fname := "Old name"
	updateName(&fname)
	fmt.Println(fname)

	// var localVar = 10 //private start with lowercase
	// var GlobVar = 20 //public start with uppercase

	region, continent := location("Irvine")
    fmt.Printf("John works in %s, %s\n", region, continent)
	
	var email = regexp.MustCompile(`^[^@]+@[^@.]+\.[^@.]+`)
    var phone = regexp.MustCompile(`^[(]?[0-9][0-9][0-9][). \-]*[0-9][0-9][0-9][.\-]?[0-9][0-9][0-9][0-9]`)

    contact := "foo@bar.com"

    switch {
    case email.MatchString(contact):
        fmt.Println(contact, "is an email")
    case phone.MatchString(contact):
        fmt.Println(contact, "is a phone number")
    default:
        fmt.Println(contact, "is not recognized")
    }

	// break != fallthrough. It continuous cases without any validations
	switch num := 15; {
    case num < 50:
        fmt.Printf("%d is less than 50\n", num)
        fallthrough
    case num > 100:
        fmt.Printf("%d is greater than 100\n", num)
        fallthrough
    case num < 200:
        fmt.Printf("%d is less than 200", num)
    }

	// for loop
	sum := 0
    for i := 1; i <= 5; i++ {
        sum += i
    }
    fmt.Println("sum of 1..5 is", sum)

	// infinite loop, go doesn't has while loop
	var num int64
	rand.Seed(time.Now().Unix())
    for num != 5 {
        num = rand.Int63n(15)
        fmt.Println(num)

		if num == 2{
			break
		}
		if num % 2 == 0{
			continue
		}
    }

	// defer used to postpone the running of a func, then it will run in reverse order
	for i:=1;i<5;i++{
		defer fmt.Println("defered value:\t",i)
		fmt.Println("regular value:\t",i)
	}

	highlow(3,1)
	fmt.Println("High low Program finished! ")	

	//recover
	defer func() {
		handler := recover()
			if handler != nil {
				fmt.Println("main(): recover", handler)
			}
		}()

	highlow(2, 0)
	fmt.Println("Program finished successfully!")

}

func mult(num1 string, num2 string) int{
	int1, _ := strconv.Atoi(num1)
	int2, _ := strconv.Atoi(num2)
	return int1 * int2
}
func divn(num1 string, num2 string) (result int){
	int1, _ := strconv.Atoi(num1)
	int2, _ := strconv.Atoi(num2)
	result = int1 / int2

	return
}
func calc(num1 int, num2 int) (mod int, sub int){
	mod = num1 % num2
	sub = num1 - num2

	return
}
//call by reference
func updateName(name *string){
	*name = "New name"
}

// private func, called only within package
func localFunc(num1 int)(num int){
	num = num1 / 3
	return
}

//global func, called anywhere
func GlobalFunc(num1 int)(num int){
	num = num1 / 3
	return
}

// switch conditionals
func location(city string) (string, string) {
    var region string
    var continent string
    switch city {
    case "Delhi", "Hyderabad", "Mumbai", "Chennai", "Kochi":
        region, continent = "India", "Asia"
    case "Lafayette", "Louisville", "Boulder":
        region, continent = "Colorado", "USA"
    case "Irvine", "Los Angeles", "San Diego":
        region, continent = "California", "USA"
    default:
        region, continent = "Unknown", "Unknown"
    }
    return region, continent
}

// defer and panic
func highlow(high int, low int) {
    if high < low {
        fmt.Println("Panic!")
        panic("highlow() low greater than high")
    }
    defer fmt.Println("Deferred: highlow(", high, ",", low, ")")
    fmt.Println("Call: highlow(", high, ",", low, ")")

    highlow(high, low + 1)
}