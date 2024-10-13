const inputField = document.getElementById('input-num');
const fromSelection = document.getElementById('from-base');
const toSelection = document.getElementById('to-base');
const convertBtn = document.getElementById('convert-btn');
const resultField = document.getElementById('result-box');
const resetBtn = document.getElementById('reset-btn');
const swapBtn = document.querySelector('#swap-btn');
const copyBtn = document.querySelector('#copy-btn');

convertBtn.addEventListener('click', function() {
    const fromBase  = fromSelection.value;
    const input = inputField.value;
    const decimalNum = parseInt(input, fromBase);
    
    if (isNaN(decimalNum)) {
        resultField.value = "Invalid Input!";
    }
    else {
        const toBase = toSelection.value;
        const numAfterConverting = decimalNum.toString(toBase);
        resultField.value = numAfterConverting;
    }
});

resetBtn.addEventListener('click', ()=> {
    inputField.value = "";
    resultField.value = "";
});

swapBtn.addEventListener('click', () => {
    const fromVal = fromSelection.value;
    const toVal = toSelection.value;
    for (const element of fromSelection) {
        if (element.value == toVal) {
            element.setAttribute('selected', true);
        }
        else {
            element.removeAttribute('selected');
        }
    }
    for (const element of toSelection) {
        if (element.value == fromVal) {
            element.setAttribute('selected', true);
        }
        else {
            element.removeAttribute('selected');
        }
    }
});

copyBtn.addEventListener('click', () => {
    navigator.clipboard.writeText(resultField.value);
});