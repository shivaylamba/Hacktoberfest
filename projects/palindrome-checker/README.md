# Palindrome Checker

Simple client-side Palindrome Checker (HTML/CSS/JS).

## Usage
Open `index.html` in a browser (or serve with a static server). Type a phrase and press Enter or click *Check*. Punctuation, spaces and capitalization are ignored.

## Acceptance criteria
- Responsive and accessible UI (has labels, aria-live on result).
- Correctly ignores non-alphanumeric characters and case.
- Clear messages for empty input, palindrome and non-palindrome.

## Test cases
- `A man, a plan, a canal: Panama` → Palindrome
- `Hello` → Not a palindrome
- `12321` → Palindrome
- `` (empty) → prompt to enter text

## How to run locally (optional)
```bash
# from project root
python -m http.server 8000
# then open http://localhost:8000/projects/palindrome-checker/index.html
