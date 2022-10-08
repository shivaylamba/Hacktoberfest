function fun() {
    console.log("Printing Function 1");
}

fun(); // calling function after function at 1st place

function fun() {
    console.log("Printing Function 2");
}


/*
It will print "Printing Function 2"
This is happening because of hoisting.

Actually, this is a very good example of the JavaScript Hoisting concept. Generally, hoisting is not performed in other programming languages like Python, C, 
C++, or Java. A JavaScript behavior known as Hoisting allows a function or variable to be used before declaration.

Function 2 will be printed,
Because the JavaScript program is executed in 2 phases. As in the first phase, memory is assigned to the variables and functions in a memory block. here memory 
allocation happens in call stack means first in last out. So here function 2 is on top of the call stack. So in the second phase of execution fn() is called and 
function 2 is printed.

*/
