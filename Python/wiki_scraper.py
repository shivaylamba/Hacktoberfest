import sys
import time
import wikipedia
import warnings
from bs4 import GuessedAtParserWarning

warnings.filterwarnings("ignore", category=GuessedAtParserWarning)

REQUEST_DELAY = 1.0
MAX_RETRIES = 5

for line in sys.stdin:
    target = line.strip()

    if not target:
        continue

    for attempt in range(MAX_RETRIES):
        try:
            page = wikipedia.page(target)

            print(page.content)
            print("\n" + "=" * 80 + "\n")

            time.sleep(REQUEST_DELAY)
            break

        except wikipedia.exceptions.DisambiguationError as e:
            print(f"[DISAMBIGUOUS] {target}")
            print(f"Possible pages: {', '.join(e.options)}")
            time.sleep(REQUEST_DELAY)
            break

        except wikipedia.exceptions.PageError:
            print(f"[NOT FOUND] {target}")
            time.sleep(REQUEST_DELAY)
            break

        except Exception as e:
            if attempt == MAX_RETRIES - 1:
                print(f"[ERROR] {target}: {e}")
                break

            wait = 2 ** attempt
            print(
                f"[ERROR] {target}: {e}\n"
                f"Waiting {wait}s before retrying..."
            )
            time.sleep(wait)