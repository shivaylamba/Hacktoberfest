package main

import "fmt"

func sort(arr []int, n int) int {
	var writes int

	for cycleStart:=0; cycleStart<n-1; cycleStart++ {
		item := arr[cycleStart]
		pos := cycleStart

		for i:=cycleStart+1; i<n; i++ {
			if(arr[i] < item) {
				pos++
			}
		}

		if(pos == cycleStart) {
			continue
		}

		for item == arr[pos] {
			pos++
		}

		if(item != arr[pos]) {
			item, arr[pos] = arr[pos], item

			writes++
		}

		for pos!=cycleStart {
			pos = cycleStart

			for i:=cycleStart+1; i<n; i++ {
				if(arr[i] < item) {
					pos++
				}
			}

			for item == arr[pos] {
				pos++
			}

			if(item != arr[pos]) {
				item, arr[pos] = arr[pos], item
	
				writes++
			}
		}
	}

	return writes
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