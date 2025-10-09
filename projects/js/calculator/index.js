const display = document.getElementById("display");
const history = document.getElementById("history");

let currentInput = "";
let operator = "";
let previousInput = "";
let shouldResetDisplay = false;

// Initialize display
display.value = "0";

function press(value) {
  if (shouldResetDisplay) {
    display.value = "";
    shouldResetDisplay = false;
  }

  if (display.value === "0" && value !== ".") {
    display.value = "";
  }

  // Prevent multiple decimal points
  if (value === "." && display.value.includes(".")) {
    return;
  }

  // Replace operator symbols for display
  let displayValue = value;
  switch (value) {
    case "*":
      displayValue = "×";
      break;
    case "/":
      displayValue = "÷";
      break;
    case "-":
      displayValue = "−";
      break;
  }

  display.value += displayValue;

  // Store actual operator for calculation
  if (["+", "-", "*", "/"].includes(value)) {
    if (currentInput && operator && previousInput) {
      calculate();
    }
    previousInput = display.value.slice(0, -1);
    operator = value;
    shouldResetDisplay = true;
  } else {
    currentInput = display.value;
  }
}

function clearAll() {
  display.value = "0";
  history.textContent = "";
  currentInput = "";
  operator = "";
  previousInput = "";
  shouldResetDisplay = false;
}

function clearEntry() {
  display.value = "0";
  currentInput = "";
}

function deleteLast() {
  if (display.value.length > 1) {
    display.value = display.value.slice(0, -1);
  } else {
    display.value = "0";
  }
  currentInput = display.value;
}

function percentage() {
  try {
    const value = parseFloat(display.value);
    if (!isNaN(value)) {
      const result = value / 100;
      display.value = formatResult(result);
      currentInput = display.value;
    }
  } catch (e) {
    display.value = "Error";
  }
}

function calculate() {
  try {
    if (!previousInput || !operator) return;

    // Convert display symbols back to operators for calculation
    let expression = previousInput + operator + currentInput;
    expression = expression
      .replace(/×/g, "*")
      .replace(/÷/g, "/")
      .replace(/−/g, "-");

    // Show calculation in history
    history.textContent = expression + " =";

    // Safely evaluate the expression
    const result = Function('"use strict"; return (' + expression + ")")();

    if (!isFinite(result)) {
      throw new Error("Invalid calculation");
    }

    display.value = formatResult(result);

    // Reset for next calculation
    currentInput = display.value;
    operator = "";
    previousInput = "";
    shouldResetDisplay = true;
  } catch (e) {
    display.value = "Error";
    history.textContent = "Error in calculation";
    setTimeout(() => {
      clearAll();
    }, 2000);
  }
}

function formatResult(result) {
  // Handle very large or very small numbers
  if (Math.abs(result) > 1e15 || (Math.abs(result) < 1e-6 && result !== 0)) {
    return result.toExponential(6);
  }

  // Remove trailing zeros and unnecessary decimal point
  const formatted = parseFloat(result.toFixed(10)).toString();

  // Limit display to reasonable length
  if (formatted.length > 12) {
    return parseFloat(result.toPrecision(8)).toString();
  }

  return formatted;
}

// Enhanced keyboard support
document.addEventListener("keydown", (e) => {
  e.preventDefault(); // Prevent default browser behavior

  if (/\d/.test(e.key)) {
    press(e.key);
  } else if (["+", "-", "*", "/"].includes(e.key)) {
    press(e.key);
  } else if (e.key === ".") {
    press(".");
  } else if (e.key === "Enter" || e.key === "=") {
    calculate();
  } else if (e.key === "Backspace") {
    deleteLast();
  } else if (e.key === "Delete") {
    clearEntry();
  } else if (e.key.toLowerCase() === "c") {
    clearAll();
  } else if (e.key === "Escape") {
    clearAll();
  } else if (e.key === "%") {
    percentage();
  }
});

// Add button click animations
document.querySelectorAll(".btn").forEach((button) => {
  button.addEventListener("click", function () {
    this.style.transform = "scale(0.95)";
    setTimeout(() => {
      this.style.transform = "";
    }, 100);
  });
});

// Add ripple effect on button clicks
document.querySelectorAll(".btn").forEach((button) => {
  button.addEventListener("click", function (e) {
    const ripple = document.createElement("span");
    const rect = this.getBoundingClientRect();
    const size = Math.max(rect.width, rect.height);
    const x = e.clientX - rect.left - size / 2;
    const y = e.clientY - rect.top - size / 2;

    ripple.style.width = ripple.style.height = size + "px";
    ripple.style.left = x + "px";
    ripple.style.top = y + "px";
    ripple.classList.add("ripple");

    this.appendChild(ripple);

    setTimeout(() => {
      ripple.remove();
    }, 600);
  });
});

// Add CSS for ripple effect
const style = document.createElement("style");
style.textContent = `
  .ripple {
    position: absolute;
    border-radius: 50%;
    background: rgba(255, 255, 255, 0.3);
    transform: scale(0);
    animation: ripple-animation 0.6s linear;
    pointer-events: none;
  }
  
  @keyframes ripple-animation {
    to {
      transform: scale(4);
      opacity: 0;
    }
  }
`;
document.head.appendChild(style);
