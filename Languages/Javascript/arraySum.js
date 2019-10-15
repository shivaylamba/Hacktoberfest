/*
Input - Array of numbers
Output - A number (Sum of array of numbers)
*/

// Iterative
const arraySum = array => {
    let sum = 0;
    for (const num of array) {
        sum += num;
    }
    return sum;
}

// Recursive
const arraySumRecursive = array => 
	array.length ? array[0] + arraySum(array.slice(1)) : 0;
;

// Functional
const arraySumFunctional = array => 
	array.reduce((sum, number) => sum + number, 0);
;
