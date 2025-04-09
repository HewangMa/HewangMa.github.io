package main

import (
	"fmt"
	"sort"
	"testing"
)

func Merge(nums1 []int, m int, nums2 []int, n int) {
	copy(nums1[m:], nums2)
	sort.Ints(nums1)
}

func TestMerge(t *testing.T) {
	nums1 := []int{1, 2, 4, 5, 0, 0, 0}
	nums2 := []int{1, 2, 7}
	m := 4
	n := 3
	Merge(nums1, m, nums2, n)
	fmt.Println(nums1)
}
