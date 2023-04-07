is_even = (number) ->
  if !isNaN(number)
    number % 2 == 0
  else
    "That's not a number"

# Call the function and prints it
console.log is_even prompt("Enter a number:")