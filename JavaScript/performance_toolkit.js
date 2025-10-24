// performance_toolkit.js
// Advanced JavaScript utilities for performance and optimization
// Author: Arshad Mahalkari

/**
 * Debounce delays execution until the user stops triggering the function
 * @param {Function} func - function to debounce
 * @param {number} delay - delay in milliseconds
 * @returns {Function} debounced function
 * @example
 * const debounced = debounce(() => console.log("Done"), 300);
 * window.addEventListener("resize", debounced);
 */
function debounce(func, delay = 300) {
  if (typeof func !== 'function') throw new TypeError('Expected a function');
  let timeout;
  return (...args) => {
    clearTimeout(timeout);
    timeout = setTimeout(() => func.apply(this, args), delay);
  };
}

/**
 * Throttle ensures a function executes only once in a given interval
 * @param {Function} func - function to throttle
 * @param {number} limit - time interval in milliseconds
 * @returns {Function} throttled function
 * @example
 * const throttled = throttle(() => console.log("Scrolling"), 1000);
 * window.addEventListener("scroll", throttled);
 */
function throttle(func, limit = 300) {
  if (typeof func !== 'function') throw new TypeError('Expected a function');
  let waiting = false;
  return (...args) => {
    if (!waiting) {
      func.apply(this, args);
      waiting = true;
      setTimeout(() => (waiting = false), limit);
    }
  };
}

/**
 * Memoize caches results of expensive function calls
 * @param {Function} func - function to memoize
 * @returns {Function} memoized function
 * @example
 * const squared = memoize((n) => n * n);
 * squared(5); // calculates
 * squared(5); // returns cached
 */
function memoize(func) {
  if (typeof func !== 'function') throw new TypeError('Expected a function');
  const cache = new Map();
  return (...args) => {
    const key = JSON.stringify(args);
    if (cache.has(key)) return cache.get(key);
    const result = func(...args);
    cache.set(key, result);
    return result;
  };
}

/**
 * Deep clone an object or array to prevent reference bugs
 * @param {Object|Array} obj - object or array to clone
 * @returns {Object|Array} cloned object/array
 * @example
 * const original = { a: 1, b: { c: 2 } };
 * const copy = deepClone(original);
 */
function deepClone(obj) {
  if (obj === null || typeof obj !== 'object') return obj;
  if (Array.isArray(obj)) return obj.map(deepClone);
  const cloned = {};
  for (const [key, value] of Object.entries(obj)) {
    cloned[key] = deepClone(value);
  }
  return cloned;
}

// Example usage
const expensiveCalc = memoize((n) => {
  console.log("Calculating...");
  return n * n;
});

const logScroll = throttle(() => console.log("Scrolling..."), 1000);
const inputChange = debounce(() => console.log("Typing stopped"), 500);

console.log("Memoize Test:", expensiveCalc(10)); // Calculating...
console.log("Memoize Cached:", expensiveCalc(10)); // From cache
console.log("DeepClone Test:", deepClone({ a: 1, b: { c: 2 } }));

// Export for Node.js and browser
if (typeof module !== 'undefined' && module.exports) {
  module.exports = { debounce, throttle, memoize, deepClone };
} else {
  window.performanceToolkit = { debounce, throttle, memoize, deepClone };
}
