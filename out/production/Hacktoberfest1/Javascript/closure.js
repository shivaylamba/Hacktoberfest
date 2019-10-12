function buildFunctions(){
    var arr=[];
    for(var i=0;i<3;i++){
        arr.push(function(){console.log(i)}())
    }
    return arr;
}
var fn=buildFunctions();
fn[0];
fn[1];
fn[2];