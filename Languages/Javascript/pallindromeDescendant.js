const palindrome = str => str === str.split('').reverse().join('');

const palindromeDescendant = num => {
  const str = String(num);

  if (palindrome(str)) return true;
  if (str.length !== 2) {
    return palindromeDescendant(
      Number(
        str.replace(
          /.{2}/g,
          ([first, second]) => Number(first) + Number(second)
        )
      )
    );
  }

  return false;
};