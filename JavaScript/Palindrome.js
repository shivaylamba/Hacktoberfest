function isPalindrome(str) {
  const cleaned = str.toLowerCase().replace(/[^a-z0-9]/g, "");
  return cleaned === cleaned.split("").reverse().join("");
}

const test = "Racecar";
console.log(`${test} → ${isPalindrome(test) ? "Palindrome" : "Not a palindrome"}`);