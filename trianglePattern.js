
const rows = 4;
for(let i = 1 ; i <=rows ; i++){
    for(let j = 1 ; j <= rows-i ; j++){
        process.stdout.write(" ")
    } 
    for(let j = 1 ; j <=i ; j++){
        process.stdout.write("*")
    }
    process.stdout.write("\n")
    
}