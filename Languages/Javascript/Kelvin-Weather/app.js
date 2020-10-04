// constant kelvin variable decraltion having value 293
const kelvin = 0

// convert kelvin to celius
let celsius = kelvin -273

// farenheit convertion
// used .floor() method to rounfd up the value
var fahrenheit = Math.floor(celsius * (9/5) + 32)

console.log(`The temperature is ${fahrenheit} degrees Fahrenheit.`)