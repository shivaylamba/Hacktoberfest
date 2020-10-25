package main

import (
	"sort"
)

// SortableInts is an example of a type that implements the sort.Interface
// and that can be used with the InsertionSort function.
type SortableInts []int

func (s SortableInts) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s SortableInts) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s SortableInts) Len() int {
	return len(s)
}

// InsertionSort defines the implementation of the algorithm in Go.
func InsertionSort(elements sort.Interface) sort.Interface {
	var n = elements.Len()
	for i := 1; i < n; i++ {
		j := i
		for j > 0 {
			if elements.Less(j-1, j) {
				elements.Swap(j-1, j)
			}
			j = j - 1
		}
	}
	return elements
}
