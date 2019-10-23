const hammingDistance = (string1, string2) => {
  let diff = 0;

  string1 = string1.toString();
  string2 = string2.toString();

  if(string1.length == string2.length) {
      for(var a = 0; a < string1.length; a++) {
          if(string1[a] != string2[a]) 
              diff += 1
      }
  }

  return diff
}

module.exports = {
  hamming: hammingDistance,
}