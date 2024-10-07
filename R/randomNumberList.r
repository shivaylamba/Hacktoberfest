num1 <- readline("Enter 1st number: ")
num2 <- readline("Enter 2nd number: ")

randomNumListWithRptdValues <- list(sample(num1 : num2, size = 10, replace = T)) 
randomNumListWithNoRptdValues <- list(sample(num1 : num2, size = 10, replace = F)) 

print(randomNumListWithRptdValues)
print(randomNumListWithNoRptdValues)