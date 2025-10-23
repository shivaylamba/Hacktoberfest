function isPalindrome(str){
    let newStr = str.toLowerCase().replace(/[^a-z0-9]/gi, '');
    let reverseStr = newStr.split('').reverse().join('');
    return reverseStr === newStr;
}

// Testing
console.log(isPalindrome('Racecar'));