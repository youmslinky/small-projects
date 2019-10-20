from nltk.corpus import words
import re
import random

left = 'qwertasdfgzxcvb'
right = 'yuiophjklnm'

def classify_left_right(word):
    lr = ''
    if word[0] in right:
        lr += 'r'
    else:
        lr += 'l'
    if word[-1] in right:
        lr += 'r'
    else:
        lr += 'l'
    return lr

def create_filter():
    myRe = re.compile('^(?:[{0}][{1}])+[{0}]?$|^(?:[{1}][{0}])+[{1}]?$'.format(left,right))
    return myRe

if __name__ == "__main__":
    word_list = words.words()

    myRe = create_filter();
    myWords = list(filter(myRe.search,word_list))

    print((' '.join(myWords)))
    print()

    while True:
        secureRandom = random.SystemRandom()
        p=''
        for i in range(5):
                p += secureRandom.choice(myWords) + ' '
        print(p)
        n = input()
        if n != '':
            break

