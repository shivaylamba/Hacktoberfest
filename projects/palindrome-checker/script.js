const input = document.getElementById('inputText');
const checkBtn = document.getElementById('checkBtn');
const clearBtn = document.getElementById('clearBtn');
const result = document.getElementById('result');

function normalize(s){
  // remove non-alphanumeric characters and lowercase
  return s.toLowerCase().replace(/[^a-z0-9]/g, '');
}

function isPalindrome(s){
  const t = normalize(s);
  // treat empty input as null to show friendly message
  if (t.length === 0) return null;
  let i=0, j=t.length-1;
  while(i<j){
    if (t[i] !== t[j]) return false;
    i++; j--;
  }
  return true;
}

function showResult(value){
  if (value === null){
    result.textContent = 'Please enter some characters to check.';
    result.className = 'result fail';
    result.classList.remove('hidden');
    return;
  }
  if (value){
    result.textContent = '✅ It is a palindrome!';
    result.className = 'result success';
  } else {
    result.textContent = '❌ Not a palindrome.';
    result.className = 'result fail';
  }
  result.classList.remove('hidden');
}

// events
checkBtn.addEventListener('click', () => {
  showResult(isPalindrome(input.value));
});
clearBtn.addEventListener('click', () => {
  input.value='';
  result.classList.add('hidden');
  input.focus();
});
input.addEventListener('keydown', (e) => {
  if (e.key === 'Enter') {
    showResult(isPalindrome(input.value));
  }
});
