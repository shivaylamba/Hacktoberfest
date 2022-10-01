function getLowest(array) {
  if (array.length == 0) return undefined;
  let lowest = array[0];

  for (let i = 1; i < array.length; i++) {
    if (array[i] < lowest) {
      lowest = array[i];
    }
  }
  return lowest;
}

let lowest = getLowest([1, 4, 5, 1, 7, 8, 9, 0]);
console.log(lowest);
