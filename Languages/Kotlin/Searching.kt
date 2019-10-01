package com.codingblocks

object Searching {

    // Linear search
    fun linear(nums: IntArray, item: Int): Int {
        for (i in nums.indices) {
            if (nums[i] == item)
                return item
        }
        return -1
    }


    // Binary Search: Only for sorted data
    fun binary(nums: IntArray, item: Int): Int {
        var start = 0
        var end = nums.size - 1
        while (start <= end) {
            val mid = (start + end) / 2

            if (item == nums[mid])
                return mid
            else if (item > nums[mid])
                start = mid + 1
            else if (item < nums[mid])
                end = mid - 1
        }
        return -1
    }


    @JvmStatic
    fun main(args: Array<String>) {
        val data = intArrayOf(12, 34, 56, 78, 79, 90)
        val found = binary(data, 78)
        println(found)
    }

}
