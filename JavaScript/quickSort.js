// Sorts an array of numbers, using the quicksort algorithm.
// Use the spread operator (...) to clone the original array, arr.
// If the length of the array is less than 2, return the cloned array.
// Use Math.floor() to calculate the index of the pivot element.
// Use Array.prototype.reduce() and Array.prototype.push() to split the array into two subarrays (elements smaller or equal to the pivot and elements greater than it), destructuring the result into two arrays.
// Recursively call quickSort() on the created subarrays.


const quickSort = arr => {
    const a = [...arr];
    if (a.length < 2) return a;
    const pivotIndex = Math.floor(arr.length / 2);
    const pivot = a[pivotIndex];
    const [lo, hi] = a.reduce(
      (acc, val, i) => {
        if (val < pivot || (val === pivot && i != pivotIndex)) {
          acc[0].push(val);
        } else if (val > pivot) {
          acc[1].push(val);
        }
        return acc;
      },
      [[], []]
    );
    return [...quickSort(lo), pivot, ...quickSort(hi)];
  };