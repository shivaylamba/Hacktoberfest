<?php
// Palindrome Checker
function isPalindrome($str) {
    $str = strtolower(preg_replace("/[^A-Za-z0-9]/", '', $str));
    return $str === strrev($str);
}

// Example
echo isPalindrome("A man a plan a canal Panama") ? "Yes" : "No"; // Yes
?>