let numOfSquares = 6;
let colors = [];
let pickedColor;

const mainBgColor = "steelblue";
const gameBgColor = "#232323"

const h1 = document.querySelector("h1");
const squares = document.querySelectorAll(".square");
const colorDisplay = document.getElementById("colorDisplay");
const messageDisplay = document.getElementById("message");

const resetButton = document.getElementById("reset");
const modeButtons = document.querySelectorAll(".mode");

// initialize gameboard
init();

function init() {
	setupModeButtons();
	setupSquares();
	reset();
}

function setupModeButtons() { 
	for(let i = 0; i < modeButtons.length; i++) {
		modeButtons[i].addEventListener("click", function() {
			modeButtons[0].classList.remove("selected");
			modeButtons[1].classList.remove("selected");
			this.classList.add("selected");
			this.textContent === "Easy" ? numOfSquares = 3: numOfSquares = 6;
			reset();
		})
	}
}

function setupSquares() {
	for(let i = 0; i < squares.length; i++) {
		// add click listeners to squares
		squares[i].addEventListener("click", function() {
			// grab clicked color
			let clickedColor = this.style.backgroundColor;
			// compare color 
			if(clickedColor === pickedColor) {
				messageDisplay.textContent = "Correct";
				resetButton.textContent = "Play Again?";
				changeColors(clickedColor);
				h1.style.backgroundColor = clickedColor;
			} else {
				messageDisplay.textContent = "Try again";
				this.style.backgroundColor = gameBgColor;
			}
		});
	}
}

function reset() {
	// generate all new colors
	colors = generateRandomColors(numOfSquares);
	// pick a new random color from array
	pickedColor = pickColor();
	// change color display to match picked colors
	colorDisplay.textContent = pickedColor;
	resetButton.textContent = "New Colors";
	messageDisplay.textContent = "";
	// change colors of squares
	for(let i = 0; i < squares.length; i++){
		if(colors[i]) {
			squares[i].style.display = "block";
			squares[i].style.background = colors[i];
		} else {
			squares[i].style.display = "none";
		}
	}
	h1.style.backgroundColor = mainBgColor;
}

resetButton.addEventListener("click", function() {
	reset();
})

function changeColors(color) {
	// loop through all squares
	for(let i = 0; i < colors.length; i++) {
		// change each color to match correct color
		squares[i].style.backgroundColor = color;
	}
}

function pickColor() {
	let random = Math.floor(Math.random() * colors.length);
	return colors[random];
}

function generateRandomColors(num) {
	// make an array
	let arr = [];
	// add num random colors to array
	for(let i = 0; i < num; i++) {
		// get random color and push into arr
		arr.push(randomColor())
	}
	// return array
	return arr;
}

function randomColor() {
	// pick a "red" from 0 to 255
	let r = Math.floor(Math.random() * 256);
	// pick a "green" from 0 to 255
	let g = Math.floor(Math.random() * 256);
	// pick a "blue" from 0 to 255
	let b = Math.floor(Math.random() * 256);
	return "rgb(" + r + ", " + g + ", " + b + ")"; 
}