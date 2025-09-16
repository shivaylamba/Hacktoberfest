const CONFIG = {
  canvas: {
    defaultWidth: 640,
    defaultHeight: 360,
    minSize: 100,
  },
  rectangle: {
    minSizePercent: 0.1,
    maxSizePercent: 0.5,
    fillAlpha: 0.75,
    strokeAlpha: 1.0,
    minStrokeWidth: 1,
    maxStrokeWidth: 6,
    autoDrawInterval: 300,
  },
  color: {
    min: 0,
    max: 255,
  },
};

// Application state
let autoDrawInterval = null;
let isAutoDrawing = false;

// DOM elements
const canvas = document.getElementById('c');
const ctx = canvas.getContext('2d');
const drawBtn = document.getElementById('drawBtn');
const startBtn = document.getElementById('startBtn');
const stopBtn = document.getElementById('stopBtn');
const clearBtn = document.getElementById('clearBtn');
const resizeBtn = document.getElementById('resizeBtn');
const widthInput = document.getElementById('widthInput');
const heightInput = document.getElementById('heightInput');
const canvasContainer = document.querySelector('.canvas-container');

// Initialize application
function init() {
  setupCanvas();
  setupEventListeners();
  updateButtonStates();
}

// Setup canvas with default settings
function setupCanvas() {
  canvas.width = CONFIG.canvas.defaultWidth;
  canvas.height = CONFIG.canvas.defaultHeight;
  ctx.fillStyle = '#ffffff';
  ctx.fillRect(0, 0, canvas.width, canvas.height);
}

// Setup all event listeners
function setupEventListeners() {
  drawBtn.addEventListener('click', drawSingleRectangle);
  startBtn.addEventListener('click', startAutoDrawing);
  stopBtn.addEventListener('click', stopAutoDrawing);
  clearBtn.addEventListener('click', clearCanvas);
  resizeBtn.addEventListener('click', resizeCanvas);

  // Keyboard accessibility
  document.body.addEventListener('keydown', handleKeyPress);

  // Input validation
  widthInput.addEventListener('input', validateInput);
  heightInput.addEventListener('input', validateInput);
}

// Handle keyboard input
function handleKeyPress(event) {
  if (event.code === 'Space' && event.target === document.body) {
    event.preventDefault();
    drawSingleRectangle();
  }
}

// Validate numeric inputs
function validateInput(event) {
  const input = event.target;
  const value = parseInt(input.value);

  if (value < CONFIG.canvas.minSize) {
    input.value = CONFIG.canvas.minSize;
  } else if (value > 2000) {
    input.value = 2000;
  }
}

// Generate random number between min and max (inclusive)
function randomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Generate random color with specified alpha
function randomColor(alpha = 1) {
  const r = randomInt(CONFIG.color.min, CONFIG.color.max);
  const g = randomInt(CONFIG.color.min, CONFIG.color.max);
  const b = randomInt(CONFIG.color.min, CONFIG.color.max);
  return `rgba(${r}, ${g}, ${b}, ${alpha})`;
}

// Generate random rectangle properties
function generateRandomRectangle() {
  const minWidth = Math.floor(canvas.width * CONFIG.rectangle.minSizePercent);
  const maxWidth = Math.floor(canvas.width * CONFIG.rectangle.maxSizePercent);
  const minHeight = Math.floor(canvas.height * CONFIG.rectangle.minSizePercent);
  const maxHeight = Math.floor(canvas.height * CONFIG.rectangle.maxSizePercent);

  const width = randomInt(minWidth, maxWidth);
  const height = randomInt(minHeight, maxHeight);

  // Ensure rectangle fits within canvas bounds
  const maxX = canvas.width - width;
  const maxY = canvas.height - height;

  const x = randomInt(0, Math.max(0, maxX));
  const y = randomInt(0, Math.max(0, maxY));

  const fillColor = randomColor(CONFIG.rectangle.fillAlpha);
  const strokeColor = randomColor(CONFIG.rectangle.strokeAlpha);
  const strokeWidth = randomInt(
    CONFIG.rectangle.minStrokeWidth,
    CONFIG.rectangle.maxStrokeWidth
  );

  return { x, y, width, height, fillColor, strokeColor, strokeWidth };
}

// Draw a single rectangle on canvas
function drawRectangle(rect) {
  ctx.save();

  // Set fill properties
  ctx.fillStyle = rect.fillColor;
  ctx.fillRect(rect.x, rect.y, rect.width, rect.height);

  // Set stroke properties for crisp rendering
  ctx.strokeStyle = rect.strokeColor;
  ctx.lineWidth = rect.strokeWidth;

  // Offset by 0.5 for crisp lines when stroke width is odd
  const offset = rect.strokeWidth % 2 === 1 ? 0.5 : 0;
  ctx.strokeRect(rect.x + offset, rect.y + offset, rect.width, rect.height);

  ctx.restore();
}

// Draw a single random rectangle
function drawSingleRectangle() {
  const rect = generateRandomRectangle();
  drawRectangle(rect);

  // Add visual feedback
  canvasContainer.classList.add('drawing');
  setTimeout(() => {
    canvasContainer.classList.remove('drawing');
  }, 300);
}

// Start automatic rectangle generation
function startAutoDrawing() {
  if (isAutoDrawing) return;

  isAutoDrawing = true;
  autoDrawInterval = setInterval(
    drawSingleRectangle,
    CONFIG.rectangle.autoDrawInterval
  );
  updateButtonStates();
}

// Stop automatic rectangle generation
function stopAutoDrawing() {
  if (!isAutoDrawing) return;

  isAutoDrawing = false;
  if (autoDrawInterval) {
    clearInterval(autoDrawInterval);
    autoDrawInterval = null;
  }
  updateButtonStates();
}

// Clear the entire canvas
function clearCanvas() {
  ctx.fillStyle = '#ffffff';
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  // Add visual feedback
  canvas.style.transition = 'opacity 0.2s ease';
  canvas.style.opacity = '0.7';
  setTimeout(() => {
    canvas.style.opacity = '1';
    setTimeout(() => {
      canvas.style.transition = '';
    }, 200);
  }, 100);
}

// Resize canvas to specified dimensions
function resizeCanvas() {
  const newWidth = Math.max(
    CONFIG.canvas.minSize,
    parseInt(widthInput.value) || CONFIG.canvas.defaultWidth
  );
  const newHeight = Math.max(
    CONFIG.canvas.minSize,
    parseInt(heightInput.value) || CONFIG.canvas.defaultHeight
  );

  // Update input values to reflect validated values
  widthInput.value = newWidth;
  heightInput.value = newHeight;

  // Resize canvas
  canvas.width = newWidth;
  canvas.height = newHeight;

  // Clear canvas with white background
  ctx.fillStyle = '#ffffff';
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  // Add resize feedback
  resizeBtn.classList.add('loading');
  setTimeout(() => {
    resizeBtn.classList.remove('loading');
  }, 500);
}

// Update button states based on current application state
function updateButtonStates() {
  startBtn.disabled = isAutoDrawing;
  stopBtn.disabled = !isAutoDrawing;

  // Update button text for better UX
  if (isAutoDrawing) {
    startBtn.textContent = 'Drawing...';
  } else {
    startBtn.textContent = 'Start';
  }
}

// Handle visibility change to pause auto-drawing when tab is hidden
document.addEventListener('visibilitychange', function () {
  if (document.hidden && isAutoDrawing) {
    stopAutoDrawing();
  }
});

// Handle window resize for responsive canvas
window.addEventListener('resize', function () {
  // Ensure canvas doesn't exceed viewport on mobile
  if (window.innerWidth < 768) {
    const maxWidth = window.innerWidth - 40; // Account for padding
    if (canvas.width > maxWidth) {
      const ratio = canvas.height / canvas.width;
      widthInput.value = Math.floor(maxWidth);
      heightInput.value = Math.floor(maxWidth * ratio);
    }
  }
});

// Error handling for canvas operations
function handleCanvasError(error) {
  console.error('Canvas operation failed:', error);

  // Show user-friendly error message
  const errorMsg = document.createElement('div');
  errorMsg.textContent = 'An error occurred while drawing. Please try again.';
  errorMsg.style.cssText = `
        position: fixed;
        top: 20px;
        right: 20px;
        background: var(--color-error);
        color: white;
        padding: 12px 16px;
        border-radius: 8px;
        z-index: 1000;
        font-size: 14px;
        box-shadow: 0 4px 6px rgba(0,0,0,0.1);
    `;

  document.body.appendChild(errorMsg);
  setTimeout(() => {
    document.body.removeChild(errorMsg);
  }, 3000);
}

// Wrap canvas operations in try-catch
const originalDrawRectangle = drawRectangle;
drawRectangle = function (rect) {
  try {
    originalDrawRectangle(rect);
  } catch (error) {
    handleCanvasError(error);
  }
};

// Initialize application when DOM is loaded
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', init);
} else {
  init();
}
