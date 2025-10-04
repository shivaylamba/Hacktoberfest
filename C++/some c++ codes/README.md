# 1. Sum of Elements Up to Target in Matrix
Given an m x n integer matrix where each row is sorted and the first element of each row is greater than the last element of the previous row, return the sum of all elements less than or equal to a given target.

## Problem Explanation 🚀
Iterate through the matrix and add elements until reaching one that is greater than the target. Stop early due to the sorted property.

## Logic 🦯
* Approach: Traverse row by row, column by column. Stop adding when element > target.
* Own test case: `matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 10` → Output = 26
* Code Structure: Simple nested loops using `vector<vector<int>>`. Libraries used: `<iostream>`, `<vector>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(m*n) worst case, but early break makes it faster
Space Complexity -> O(1)
```

---

# 2. Valid Anagram
Given two strings, return true if one is an anagram of the other.

## Problem Explanation 🚀
Two strings are anagrams if they contain the same characters with the same frequencies.

## Logic 🦯
* Approach: Count frequency of each character in one string, subtract using the second string. If counts match → anagram.
* Own test case: `s = "anagram", t = "nagaram"` → true; `s = "rat", t = "car"` → false
* Code Structure: `vector<int>` of size 26 to store counts, loop through strings. Libraries: `<iostream>`, `<string>`, `<vector>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1) (constant array of size 26)
```

---

# 3. Majority Element
Find the element in an array that appears more than n/2 times.

## Problem Explanation 🚀
The element that occurs more than half the times is the majority element; always exists in the array.

## Logic 🦯
* Approach: Boyer-Moore Voting Algorithm: keep a candidate and count, cancel out different elements.
* Own test case: `nums = [3,2,3]` → Output = 3
* Code Structure: Single loop with candidate and count. Libraries: `<iostream>`, `<vector>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1)
```

---

# 4. Maximum Subarray
Find the contiguous subarray with the largest sum.

## Problem Explanation 🚀
Use Kadane’s algorithm to track current sum and max sum while traversing the array.

## Logic 🦯
* Approach: At each step, either extend current subarray or start new subarray; update max sum.
* Own test case: `nums = [-2,1,-3,4,-1,2,1,-5,4]` → Output = 6 ([4,-1,2,1])
* Code Structure: Single loop. Libraries: `<iostream>`, `<vector>`, `<climits>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1)
```

---

# 5. Pattern Searching
Print all occurrences of a pattern in a text.

## Problem Explanation 🚀
Check for the pattern starting at each possible index in the text.

## Logic 🦯
* Approach: Nested loops: outer for text start index, inner for pattern match.
* Own test case: `txt = "AABAACAADAABAABA", pat = "ABA"` → Output: indices 1, 10, 13
* Code Structure: Loops and condition checking. Libraries: `<iostream>`, `<cstring>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O((n-m+1)*m)
Space Complexity -> O(1)
```

---

# 6. Pivot Index
Find the index where left sum equals right sum.

## Problem Explanation 🚀
Iterate while maintaining left sum and compare with right sum (total sum - left sum - current).

## Logic 🦯
* Approach: Compute total sum first, then iterate to find index where left sum equals right sum.
* Own test case: `nums = [1,7,3,6,5,6]` → Output = 3
* Code Structure: Single loop, integer variables. Libraries: `<iostream>`, `<vector>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1)
```

---

# 7. Product Except Pivot
Compute product of all elements except the pivot element.

## Problem Explanation 🚀
Multiply all elements except the pivot value.

## Logic 🦯
* Approach: Loop through array and multiply only if element != pivot.
* Own test case: `nums = [1,3,5,6,2], pivot = 5` → Output = 36
* Code Structure: Loop and conditional multiplication. Libraries: `<iostream>`, `<vector>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1)
```

---

# 8. Best Time to Buy and Sell Stock
Maximize profit by buying and selling once.

## Problem Explanation 🚀
Track minimum price and compute profit at each step; update max profit.

## Logic 🦯
* Approach: Iterate array, keep `minPrice` and update `maxProfit = max(maxProfit, price-minPrice)`
* Own test case: `prices = [7,1,5,3,6,4]` → Output = 5
* Code Structure: Single loop. Libraries: `<iostream>`, `<vector>`, `<climits>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1)
```

---

# 9. Roman to Integer
Convert a Roman numeral string to an integer.

## Problem Explanation 🚀
Add values of symbols, subtract if a smaller symbol comes before a larger one.

## Logic 🦯
* Approach: Map characters to values, traverse string, check next character to decide addition/subtraction.
* Own test case: `"III" → 3`, `"IV" → 4`, `"MCMXCIV" → 1994`
* Code Structure: `unordered_map<char,int>`, loop through string. Libraries: `<iostream>`, `<unordered_map>`, `<string>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n)
Space Complexity -> O(1)
```

---

# 10. Segregate 0s and 1s
Sort array so that all 0s are on the left and 1s on the right.

## Problem Explanation 🚀
Place all 0s before 1s; simplest approach using sort function.

## Logic 🦯
* Approach: Use built-in `sort()` on array; works because array has only 0s and 1s.
* Own test case: `arr = [0,1,0,1,0,0,1,1,1,0]` → Output = `[0,0,0,0,0,1,1,1,1,1]`
* Code Structure: `sort(arr.begin(), arr.end())`. Libraries: `<iostream>`, `<vector>`, `<algorithm>`

## Time Complexity and Space Complexity
```cpp
Time Complexity -> O(n log n)
Space Complexity -> O(1)
```