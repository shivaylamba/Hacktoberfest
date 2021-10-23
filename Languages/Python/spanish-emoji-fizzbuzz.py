# fizzbuzz time!
# kwame taylor

from emoji import emojize
import googletrans
import inflect

def run_fizzbuzz(i):
    '''
    This function runs Kwame's fizzbuzz, which prints out numbers from 1 to i,
    except for each third number it prints a partying face emoji,
    every fifth number it prints a cowboy hat face emoji,
    every fifteenth number it prints a face screaming in fear emoji,
    and every other number prints as the Spanish translation of its English word.
    '''
    fizzbuzz = emojize(':face_screaming_in_fear:')
    fizz = emojize(':partying_face:')
    buzz = emojize(':cowboy_hat_face:')

    translator = googletrans.Translator()
    p = inflect.engine()

    for i in range(1, i+1):
        if i % 3 == 0 and i % 5 == 0:
            print(fizzbuzz)
        elif i % 3 == 0:
            print(fizz)
        elif i % 5 == 0:
            print(buzz)
        else:
            numword = p.number_to_words(i)
            result = translator.translate(numword, dest='es')
            print(result.text)

i = 525
run_fizzbuzz(i)