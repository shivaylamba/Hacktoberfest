
// take an array as an input, sort the even elements in ascending order such that their position will not be changed, then do the same for odd elements such that odd will remain in there indexes but in a sorted manner. Then, at the end put even numbers on even and odd on odd indexes.

let numberArray = [2, 7, 14, 5, 10, 9, 22, 35, 16,18];

console.log(`actual array: ${numberArray}`);

let evenMax;
let oddMin;

let evenIndex = 0,
    oddIndex = 0;

let evenArray = [],
oddArray = [];

function swapElement(index1, index2) {
    let temp = numberArray[index1];
    numberArray[index1] = numberArray[index2];
    numberArray[index2] = temp;
}

let indexf;
let indexs;
// for sorting evens in descending
for (let i = 0; i < numberArray.length-1; i++) {
    if (numberArray[i] % 2 == 0) {
        indexf = i;
        for (let j = i+1; j < numberArray.length; j++) {
        if (numberArray[j] % 2 == 0) {
            indexs = j;
            if (numberArray[indexf] < numberArray[indexs]) {
                swapElement(indexf, indexs);
            }
        }
        
        } 
    }
    continue
}

console.log(indexf , indexs);
// for sorting evens in descending
for (let k = 0; k < numberArray.length; k++) {
    if (numberArray[k] % 2 == 1) {
        indexf = k;
        for (let l = k; l < numberArray.length; l++) {
        if (numberArray[l] % 2 == 1) {
            indexs = l;
            if (numberArray[indexf] > numberArray[indexs]) {
                swapElement(indexf, indexs);
            }
        }
        
        } 
    }
    
}

console.log(`sorted array: ${numberArray}`)


const evenOddPlacing = (numberArray) => {


    for (let m = 0; m < numberArray.length; m++) {
        if (numberArray[m] % 2 == 0) {
            evenArray.push(numberArray[m]);
        }
        else if (numberArray[m] % 2 == 1) {
            oddArray.push(numberArray[m]);
        }
        
    }

    for (let n = 0; n < numberArray.length; n++) {
        
        if (n % 2 == 0){
            numberArray[n] = evenArray[evenIndex];
            evenIndex++;
        }
        else{
            numberArray[n] = oddArray[oddIndex];
            oddIndex++;
        }
        
    }

    console.log(`Even or evena and odd on odd \n${numberArray}`)
}

evenOddPlacing(numberArray)
