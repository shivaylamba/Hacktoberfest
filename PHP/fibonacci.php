<?php
$num = 0;
$n1 = 0;
$n2 = 1;
echo "<h3>Fibonacci series for first 12 numbers: </h3>";
echo "\n";
echo $n1 . ' ' . $n2 . ' ';
while ($num < 10) {
    $n3 = $n2 + $n1;
    echo $n3 . ' ';
    $n1 = $n2;
    $n2 = $n3;
    $num = $num + 1;
}
