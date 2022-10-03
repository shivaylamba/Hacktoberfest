function rectangleArea(W, H) {
  let area = W * H;
  document.write("Width " + H + "<br>");
  document.write("Height =" + W + "<br>");
  document.write("Area =" + area);
}
height = prompt("Height =");
width = prompt("Width =");
rectangleArea(width, height);
