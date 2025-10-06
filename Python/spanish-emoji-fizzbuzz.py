from emoji import emojize
from googletrans import Translator
import inflect

def run_fizzbuzz(n):
    # Emojis
    FIZZ = emojize(':partying_face:')
    BUZZ = emojize(':cowboy_hat_face:')
    FIZZBUZZ = emojize(':face_screaming_in_fear:')

    # Translator and number-to-words engine
    translator = Translator()
    p = inflect.engine()

    for i in range(1, n + 1):
        if i % 15 == 0:
            print(FIZZBUZZ)
        elif i % 3 == 0:
            print(FIZZ)
        elif i % 5 == 0:
            print(BUZZ)
        else:
            word = p.number_to_words(i)
            spanish = translator.translate(word, dest='es').text
            print(spanish)

# Run for 525 numbers
i = 525
run_fizzbuzz(i)
