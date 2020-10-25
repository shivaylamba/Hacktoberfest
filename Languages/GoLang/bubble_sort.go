package main

import "fmt"

func BubbleSort(numbers []int) []int {
	//Start the loop in reverse order, so the loop will start with length
	//which is equal to the length of input array and then loop untill   //reaches 1
	for i := len(numbers); i > 0; i-- {
		//The inner loop will first iterate through the full length
		//the next iteration will be through n-1
		// the next will be through n-2 and so on
		for j := 1; j < i; j++ {
			if numbers[j-1] > numbers[j] {
				intermediate := numbers[j]
				numbers[j] = numbers[j-1]
				numbers[j-1] = intermediate
			}
		}
	}
	return numbers
}

func main() {
	a := []int{2, 212, 3001, 14, 501, 7800, 9932, 33, 45, 45, 45, 91, 99, 37, 102, 102, 104, 106, 109, 106}
	fmt.Println(BubbleSort(a))
}
