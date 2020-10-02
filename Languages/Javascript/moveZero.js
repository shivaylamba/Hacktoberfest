/*
Description:
Takes an array and moves all of the zeros to the end.
*/

const moveZero = (array) =>
  array.reduceRight(
    (acc, val) => (val === 0 ? [...acc, val] : [val, ...acc]),
    []
  );

console.log(
  moveZero([false, 0, 1, 0, 1, 3, 'a']) // returns[false,1,1,3,"a",0,0]
);
