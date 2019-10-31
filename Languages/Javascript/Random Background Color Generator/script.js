
function rand()
{
    return Math.floor(Math.random()*256);
}

function rgbGenerator()
{
    return "rgb(" + rand() + "," + rand() + "," +rand() + ")";
}

var rgb;
var val;

for( i=0;i<75;i++)
{
    val = rgbGenerator();
    rgb="<div style='background-color: " + val + "'>" + val +"<br>Color</div>"
    document.write(rgb);
}