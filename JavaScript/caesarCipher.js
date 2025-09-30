#caesarCipher.js
#Caesar Cipher encoder & decoder (basic cryptography)

function caesarCipher(str, shift) {
    return str.split("").map(char => {
        if (/[a-z]/i.test(char)) {
            let base = char === char.toUpperCase() ? 65 : 97;
            return String.fromCharCode(((char.charCodeAt(0) - base + shift) % 26) + base);
        }
        return char;
    }).join("");
}

// Example usage:
console.log("Encoded:", caesarCipher("Hacktoberfest", 3));
console.log("Decoded:", caesarCipher(caesarCipher("Hacktoberfest", 3), 26 - 3));
