# Random Rectangle Art Generator

A modern, interactive HTML5 Canvas application for creating beautiful abstract geometric art through randomly generated rectangles. Built with vanilla JavaScript, this application demonstrates the power of canvas-based drawing and generative art techniques.

## 🎨 Features

- **Random Rectangle Generation**: Creates rectangles with random sizes, positions, and colors
- **Interactive Controls**: Draw single rectangles or start continuous auto-generation
- **Customizable Canvas**: Resize canvas dimensions on-the-fly
- **Accessibility Support**: Keyboard shortcuts and screen reader compatibility
- **Modern UI**: Clean, responsive design with hover effects and smooth interactions
- **Performance Optimized**: Efficient rendering with proper state management

## 🚀 Demo

The application generates abstract art by placing randomly colored and sized rectangles on an HTML5 canvas. Each rectangle has:

- Random dimensions (10-50% of canvas size)
- Random RGB colors with transparency
- Random stroke widths (1-6 pixels)
- Smart positioning to stay within canvas bounds

## 📋 Prerequisites

- Modern web browser with HTML5 Canvas support
- No additional dependencies or frameworks required

## 🛠 Installation

1. **Clone or download** the project files
2. **Ensure all files** are in the same directory:
   ```
   project-folder/
   ├── index.html
   ├── style.css
   ├── script.js
   └── README.md
   ```
3. **Open** `index.html` in your web browser

### Alternative: Direct Usage

Simply open the `index.html` file in any modern web browser - no server setup required!

## 🎮 Usage

### Basic Controls

| Control    | Action                                             |
| ---------- | -------------------------------------------------- |
| **Draw**   | Generate a single random rectangle                 |
| **Start**  | Begin continuous auto-generation (300ms intervals) |
| **Stop**   | Pause the auto-generation                          |
| **Clear**  | Remove all rectangles from canvas                  |
| **Resize** | Apply new canvas dimensions                        |

### Keyboard Shortcuts

- **Spacebar**: Generate a single rectangle (when page has focus)

### Canvas Customization

1. Enter desired **width** and **height** in the input fields
2. Click **Resize** to apply new dimensions
3. Minimum canvas size: 100x100 pixels
4. Maximum recommended: 2000x2000 pixels

## 🏗 Technical Architecture

### File Structure

```
├── index.html          # Main HTML structure
├── style.css           # Modern CSS styling with custom properties
├── script.js           # Core JavaScript functionality
└── README.md          # Project documentation
```

### Key Functions

#### `randInt(min, max)`

Generates random integers within specified range

#### `randColor(alpha)`

Creates random RGB colors with configurable transparency

#### `drawRandomRect()`

Main drawing function that:

- Calculates random rectangle dimensions
- Positions rectangles within canvas bounds
- Applies random colors and stroke styles
- Renders to canvas with crisp edges

### Canvas Configuration

```javascript
// Default settings
Canvas Size: 640x360 pixels
Rectangle Size Range: 10-50% of canvas dimensions
Fill Alpha: 0.75 (semi-transparent)
Stroke Alpha: 1.0 (opaque)
Auto-draw Interval: 300ms
Stroke Width Range: 1-6 pixels
```

## 🎨 Styling Features

- **Modern Design System**: CSS custom properties for consistent theming
- **Responsive Layout**: Flexbox-based responsive design
- **Interactive Feedback**: Hover effects and button state changes
- **Accessibility**: High contrast and keyboard navigation support
- **Cross-platform Fonts**: System font stack for native appearance

## 🌐 Browser Compatibility

| Browser | Support         |
| ------- | --------------- |
| Chrome  | ✅ Full Support |
| Firefox | ✅ Full Support |
| Safari  | ✅ Full Support |
| Edge    | ✅ Full Support |
| Opera   | ✅ Full Support |

**Minimum Requirements:**

- HTML5 Canvas support
- ES6+ JavaScript features
- CSS3 custom properties

## 🔧 Configuration Options

### Customizing Rectangle Properties

Edit the following variables in `script.js`:

```javascript
// Rectangle size range (percentage of canvas)
const minSizePercent = 0.1; // 10%
const maxSizePercent = 0.5; // 50%

// Auto-draw timing
const autoInterval = 300; // milliseconds

// Transparency settings
const fillAlpha = 0.75; // Fill transparency
const strokeAlpha = 1.0; // Stroke transparency
```

### Customizing Colors

Modify the `randColor()` function to use specific color palettes:

```javascript
function randColor(alpha = 1) {
  // Example: Warm color palette
  const colors = [
    [255, 99, 71], // Tomato
    [255, 165, 0], // Orange
    [255, 215, 0], // Gold
    [220, 20, 60], // Crimson
  ];

  const color = colors[Math.floor(Math.random() * colors.length)];
  return `rgba(${color[0]},${color[1]},${color[2]},${alpha})`;
}
```

## 🎯 Use Cases

### Educational

- **HTML5 Canvas Tutorial**: Learn canvas drawing basics
- **JavaScript Event Handling**: Understand DOM manipulation
- **Generative Art**: Explore algorithmic creativity
- **Web Development Portfolio**: Showcase interactive skills

### Creative

- **Abstract Art Generation**: Create unique visual compositions
- **Background Patterns**: Generate textures for designs
- **Interactive Installations**: Base for larger art projects
- **Design Inspiration**: Rapid prototyping for visual ideas

### Development

- **Canvas Performance Testing**: Benchmark rendering capabilities
- **Algorithm Visualization**: Demonstrate random processes
- **UI/UX Patterns**: Test interactive design concepts
- **Cross-browser Testing**: Validate canvas implementations

## 🚀 Enhancement Ideas

### Immediate Improvements

- [ ] **Export Functionality**: Save canvas as PNG/JPEG
- [ ] **Undo/Redo**: Step-by-step canvas history
- [ ] **Preset Palettes**: Curated color schemes
- [ ] **Shape Variations**: Circles, triangles, polygons

### Advanced Features

- [ ] **Animation Effects**: Rotation, scaling, fading
- [ ] **Layering System**: Multiple canvas layers
- [ ] **Brush Modes**: Different blending modes
- [ ] **Pattern Libraries**: Saved composition templates
- [ ] **Social Sharing**: Direct sharing to social media
- [ ] **Mobile Touch**: Touch gesture support

## 🤝 Contributing

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Development Guidelines

- Follow existing code style and conventions
- Test across multiple browsers
- Update README for new features
- Consider performance implications
- Maintain accessibility standards

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🙏 Acknowledgments

- **HTML5 Canvas API**: For powerful 2D rendering capabilities
- **Modern Web Standards**: For cross-browser compatibility
- **Generative Art Community**: For inspiration and techniques
- **Web Accessibility Initiative**: For accessibility guidelines

## 📞 Support

If you encounter issues or have questions:

1. **Check Browser Compatibility**: Ensure your browser supports HTML5 Canvas
2. **Verify File Structure**: All files should be in the same directory
3. **Check Console**: Look for JavaScript errors in browser developer tools
4. **Test Different Browsers**: Try the application in multiple browsers

## 🔗 Related Projects

- [Canvas API Documentation](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API)
- [Generative Art Resources](https://github.com/topics/generative-art)
- [HTML5 Canvas Tutorials](https://www.w3schools.com/graphics/canvas_intro.asp)

---

**Made with ❤️ and HTML5 Canvas**

_Create beautiful abstract art with the power of code!_
