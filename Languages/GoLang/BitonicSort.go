package main

import "fmt"

func compAndSwap(arr []int, x int, y int, dir int) {
	if((dir==1 && arr[x]>arr[y]) || (dir==0 && arr[x]<arr[y])) {
		arr[x], arr[y] = arr[y], arr[x]
	}
}

func bitonicMerge(arr []int, low int, count int, dir int) {
	if(count > 1) {
		k := count/2
		for i:=low; i<low+k; i++ {
			compAndSwap(arr, i, i+k, dir)
		}

		bitonicMerge(arr, low, k, dir)
		bitonicMerge(arr, low+k, k, dir)
	}
}

func bitonicSort(arr []int, low int, count int, dir int) {
	if(count > 1) {
		k := count/2
		bitonicSort(arr, low, k, 1)
		bitonicSort(arr, low+k, k, 0)

		bitonicMerge(arr, low, count, dir)
	}
}

func sort(arr []int, n int, dir int) {
	bitonicSort(arr, 0, n, dir)
}

func main() {
	var n int
	dir := 1

	fmt.Printf("Enter the number of elements: ")
	fmt.Scan(&n)
	arr := make([]int, n)

	fmt.Printf("Enter the %d elements: ", n)
	for i:=0; i<n; i++ {
		fmt.Scan(&arr[i])
	}

	sort(arr, n, dir)
	fmt.Println("Sorted Array:")
	for _, x := range arr {
		fmt.Printf("%d ", x)
	}
	fmt.Println()
}
