const flattenObject = function (obj, parent) {
  let ans = {};
  const generateObject = (obj, parent) => {
    for (let key in obj) {
      let newParent = parent + key;
      let value = obj[key];
      if (typeof value === "object") {
        generateObject(value, newParent + ".");
      } else {
        ans[newParent] = value;
      }
    }
  };
  generateObject(obj, parent);
  return ans;
};

const obj = {
  a: 1,
  b: 2,
  c: {
    d: 3,
    e: 4,
    f: [5, 6],
  },
  d: 45,
};

console.log(flattenObject(obj, ""));
