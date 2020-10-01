num = 4;

function outer() {
    num = 2;
    num++;
    function inner() {
        num = 5;
        if(num>0) {
            console.log(num);
        }
        
    }
    num = 3;
    console.log(num);
}

outer();