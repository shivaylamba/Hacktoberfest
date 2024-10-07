isStringPalindrome <- function(str) {
    str <- tolower(str)
    str <- gsub(" ", "", str)
    reversedStr <- paste(rev(unlist(strsplit(str, ""))), collapse = "")
    return(str == reversedStr)
}

userInput <- readline(prompt="Enter any string: ")

if(isStringPalindrome(userInput)) {
    print("Palindrome")
} else {
    print("Not a Palindrome")
}