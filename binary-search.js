// Binary search in js
function recursiveBinarySearch(arr, x, start, end) {
  // Base Condition

  if (start > end) return "Element not found";

  // Find the middle index
  let mid = Math.floor((start + end) / 2);

  // Compare mid with given key x
  if (arr[mid] === x) return `Found ${arr[mid]} at index ${mid}`;

  // If element at mid is greater than x,
  // search in the left half of mid
  if (arr[mid] > x) return recursiveBinarySearch(arr, x, start, mid - 1);
  // If element at mid is smaller than x,
  // search in the right half of mid
  else return recursiveBinarySearch(arr, x, mid + 1, end);
}
const arr = [3, 4, 5, 2, 6];
const x = 3;

console.log(recursiveBinarySearch(arr, x, 0, arr.length - 1));
