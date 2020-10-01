/*
ATM or other PIN code allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4  or  6 digits.
*/

const validatePIN = (pin) => /^(\d{4}|\d{6})$/.test(pin);

console.log(validatePIN(1234));
console.log(validatePIN(12341));
console.log(validatePIN(12));
console.log(validatePIN(''));
