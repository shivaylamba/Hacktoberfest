package main

import "fmt"
import "math/rand"

func RandArray(n int) []int {
    arr := make([]int, n)
    for i := 0; i <= n - 1; i++ {
        arr[i] = rand.Intn(n)
    }
    return arr
}

func main() {
	arr := RandArray(10)
	fmt.Println("Unsorted array is:", arr)
	fmt.Println("")

	tmp := 0

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-1-i; j++ {
			if arr[j] > arr[j+1] {
				tmp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = tmp
			}
		}
	}
	fmt.Println("Sorted array is: ", arr)
}




