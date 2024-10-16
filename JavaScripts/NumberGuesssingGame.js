<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title> Guessing Number Game</title>
</head>
<body>
  <h1>Guess the Number Game</h1>
  <p>Guess a number between 1 and 30:</p>
  <input type="number" id="userGuess" placeholder="Enter your number">
  <button onclick="checkGuess()">Submit Guess</button>
  <p id="result"></p>

  <script>
    const randomNumber = Math.floor(Math.random() * 20) + 1;

    function checkGuess() {
      const userGuess = document.getElementById('userGuess').value;
      const result = document.getElementById('result');

      if (userGuess == randomNumber) {
        result.textContent = 'Congratulations! You guessed it right!';
      } else {
        result.textContent = 'OOPS! Try again! The number was ' + randomNumber;
      }
    }
  </script>
</body>
</html>
