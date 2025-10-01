const display = document.getElementById("display");
const buttons = document.querySelectorAll(".btn");
const equalBtn = document.getElementById("equal");
const clearBtn = document.getElementById("clear");

let input = "";

// Add click listeners to all buttons
const operators = ['+', '-', '*', '/']
buttons.forEach(button => {
  button.addEventListener("click", () => {
    const value = button.getAttribute("data-value");

    if (value) {
        const lastChar = input.slice(-1);
        if(operators.includes(value) && operators.includes(lastChar)){
            return;
        }
        
      input += value;
      display.value = input;
    }
  });
});

// Handle equal (=) button
equalBtn.addEventListener("click", () => {
  try {
    const result = eval(input); // For basic calculator; avoid eval in complex apps
    display.value = result;
    input = result.toString(); // allow further operations
  } catch {
    display.value = "Error";
    input = "";
  }
});

// Handle clear (C) button
clearBtn.addEventListener("click", () => {
  input = "";
  display.value = "";
});

const toggleThemeBtn = document.getElementById("toggle-theme");

toggleThemeBtn.addEventListener("click", () => {
  document.body.classList.toggle("dark-mode");

  if (document.body.classList.contains("dark-mode")) {
    toggleThemeBtn.textContent = "☀️ Light Mode";
  } else {
    toggleThemeBtn.textContent = "🌙 Dark Mode";
  }
});

const backspaceBtn = document.getElementById("backspace");

backspaceBtn.addEventListener("click", () => {
  input = input.slice(0, -1); // Remove last character
  display.value = input;
});