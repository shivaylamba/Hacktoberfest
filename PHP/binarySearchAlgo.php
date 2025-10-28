<?php
/**
 * Binary Search Algorithm
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

function binarySearch($arr, $target) {
    $left = 0;
    $right = count($arr) - 1;
    
    while ($left <= $right) {
        $mid = floor(($left + $right) / 2);
        
        if ($arr[$mid] == $target) {
            return $mid; // Element found
        }
        
        if ($arr[$mid] < $target) {
            $left = $mid + 1; // Search right half
        } else {
            $right = $mid - 1; // Search left half
        }
    }
    
    return -1; // Element not found
}

// Example usage
$sortedArray = [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78];
$target = 23;

$result = binarySearch($sortedArray, $target);

if ($result != -1) {
    echo "Element found at index: " . $result;
} else {
    echo "Element not found in array";
}
?>