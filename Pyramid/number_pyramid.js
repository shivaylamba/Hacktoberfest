let n = 5; 
for (let i = 1; i <= n; i++) { 
    let str = ''; 
    let count = 1; 
    for (let j = 1; j <= 2 * n; ++j) { 
        if (i + j >= n + 1 && (i >= j - n + 1)) { 
            // Add a space after each number 
            str += count.toString() + ' '; 
            count++; 
        } else { 
            // Add two spaces for the gap 
            str += '  '; 
        } 
    } 
  
    console.log(str); 
}
