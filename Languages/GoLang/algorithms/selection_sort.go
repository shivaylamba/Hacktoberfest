package main

import "sort"

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

// SelectionSort returns a sorted array using the Selection Sort algorithm.
func SelectionSort(els sort.Interface) sort.Interface {
	n := els.Len()
	for i := 0; i < n-1; i++ {
		minIndex := i
		for j := i + 1; j < n; j++ {
			if els.Less(j, minIndex) {
				minIndex = j
			}
		}
		els.Swap(minIndex, i)
	}
	return els
}
