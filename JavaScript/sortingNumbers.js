function SortNumbs(...values) {
  for (let i = 0; i < values.length; i++) {
    for (let j = i + 1; j < values.length; j++) {
      if (values[i] > values[j]) {
        temp = values[i];
        values[i] = values[j];
        values[j] = temp;
      }
    }
  }

  return values;
}

console.log(SortNumbs(2, 1, 44, 22, 1)); // [ 1, 1, 2, 22, 44 ]
console.log(SortNumbs(65, 43, 21, 90, -6, -55)); // [ -55, -6, 21, 43, 65, 90 ]
