#!/usr/bin/python
import random
              
              
syllables = ['wa', 'ra', 'ya', 'ma', 'ha', 'na', 'ta', 'sa', 'ka', 'a',
                'ri',       'mi', 'hi', 'ni', 'chi', 'shi', 'ki', 'i',
                'ru', 'yu', 'mu', 'fu', 'nu', 'tsu', 'su', 'ku', 'u',
                're',       'me', 'he', 'ne', 'te', 'se', 'ke', 'e',
          'wo', 'ro', 'yo', 'mo', 'ho', 'no', 'to', 'so', 'ko', 'o',
          'n']
 
 
def _syllable():
    return random.choice(syllables)

def create_fake_word():
    """ This function generates a fake word by creating between two and three
        random syllables and then joining them together.
    """
    syllables = []
    for x in range(random.randint(2,4)):
        syllables.append(_syllable())
    return "".join(syllables)
 
if __name__ == "__main__":
    for x in range(10):
        print(create_fake_word())
