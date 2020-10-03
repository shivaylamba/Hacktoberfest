var person = {
  name: 'John Doe',
  age: 35,
  vehicles: {
    car: {
      sport: 'Lamborghini',
      hatchback: 'Civic Turbo Hatchback',
    },
    bike: 'ktm-duke',
    plane: 'lufthansa',
  },
};

const objectGetter = (obj, path) => {
  if (!obj) return null;
  if (!path) return obj;
  const splitPath = path.split('|');
  const nextObj = obj[splitPath[0]];
  if (nextObj) {
    if (splitPath.length === 1) return nextObj;
    else {
      const remainingPath = splitPath.slice(1).join('|');
      return objectGetter(nextObj, remainingPath);
    }
  }
  return null;
};

// Example use, return => Civic Turbo Hatchback
console.log(objectGetter(person, 'vehicles|car|hatchback'));
