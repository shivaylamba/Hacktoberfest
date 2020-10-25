<?php
session_start();
session_destroy();
session_start();
header('Location: index.php'); //instead of index.php, add the page to which you want to be redirected upon logout
?>