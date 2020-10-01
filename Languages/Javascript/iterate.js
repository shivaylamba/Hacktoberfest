function filteredArray(arr, elem) {
    let newArr = [];
    // change code below this line
    var i;
    for (i=0; i<arr.length; i++){
      if (arr[i].indexOf(elem)==0) {
        newArr.push(arr[i]);
      }
    }
    // change code above this line
    return newArr;
}
  
  // change code here to test different cases:
console.log(filteredArray([[3, 2, 3], [1, 6, 3], [3, 13, 26], [19, 3, 9]], 3));
