//Simple Calculator

function cal7f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 7;
}

function cal8f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 8;
}

function cal9f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 9;
}

function cal4f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 4;
}

function cal5f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 5;
}

function cal6f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 6;
}

function cal1f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 1;
}

function cal2f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 2;
}

function cal3f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 3;
}

function cal0f(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof + 0;
}

function calCf(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = "0";
}

function calDotf(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = displaynof+".";
}



let op;
let firstNo;

function calDivf(){
    firstNo = document.getElementById("displayno").innerHTML;
    console.log(firstNo);
    document.getElementById("displayno").innerHTML = 0;
    op = "4";
}

function calMuF(){
    firstNo = document.getElementById("displayno").innerHTML;
    console.log(firstNo);
    document.getElementById("displayno").innerHTML = 0;
    op = "3";
}

function calAddf(){
    firstNo = document.getElementById("displayno").innerHTML;
    console.log(firstNo);
    document.getElementById("displayno").innerHTML = 0;
    op = "1";
}

function calSubf(){
    firstNo = document.getElementById("displayno").innerHTML;
    console.log(firstNo);
    document.getElementById("displayno").innerHTML = 0;
    op = "2";
}

function calPf(){
    firstNo = document.getElementById("displayno").innerHTML;
    console.log(firstNo);
    document.getElementById("displayno").innerHTML = 0;
    op = "5";   
}

function calEqualf(){
    let secondNo = document.getElementById("displayno").innerHTML;
    if (op == 1){
        document.getElementById("displayno").innerHTML = parseFloat(firstNo) + parseFloat(secondNo);
    }else if(op == 2){
        document.getElementById("displayno").innerHTML = parseFloat(firstNo) - parseFloat(secondNo);
    }else if(op == 3){
        document.getElementById("displayno").innerHTML = parseFloat(firstNo) * parseFloat(secondNo);
    }else if(op == 4){
        document.getElementById("displayno").innerHTML = parseFloat(firstNo) / parseFloat(secondNo);
    }else if(op == 5){
        document.getElementById("displayno").innerHTML = parseFloat(firstNo) * parseFloat(firstNo);
    }else{
        document.getElementById("displayno").innerHTML = "invalid";
    }
}

function calACf(){
    let displaynof = document.getElementById("displayno").innerHTML;
    document.getElementById("displayno").innerHTML = "0";
    firstNo = "";
}

function calEf(){
    let previous = document.getElementById("displayno").innerHTML;
    let erasedPre = previous.slice(0, -1);
    document.getElementById("displayno").innerHTML = erasedPre;
}
