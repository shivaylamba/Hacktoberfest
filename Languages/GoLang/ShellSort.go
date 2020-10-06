package main

import "fmt"

func sort(arr []int, n int) {
	for gap:=n/2; gap>0; gap/=2 {
		for i:=gap; i<n; i++ {
			temp := arr[i]
			var j int

			for j=i; j>=gap && arr[j-gap]>temp; j-=gap {
				arr[j] = arr[j-gap]
			}

			arr[j] = temp
		}
	}
}

func main() {
	var n int

	fmt.Printf("Enter the number of elements: ")
	fmt.Scan(&n)
	arr := make([]int, n)

	fmt.Printf("Enter the %d elements: ", n)
	for i:=0; i<n; i++ {
		fmt.Scan(&arr[i])
	}

	sort(arr, n)
	fmt.Println("Sorted Array:")
	for _, x := range arr {
		fmt.Printf("%d ", x)
	}
	fmt.Println()
}