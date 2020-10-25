<?php
echo "<pre>\n";
$pdo = new PDO('mysql:host=localhost;port=3306;dbname=misc',    //change dbname, port number accordingly
'foo', 'bar');      //foo and bar are the username and password I made for my misc db, change accordingly
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
echo "</pre>";
?>