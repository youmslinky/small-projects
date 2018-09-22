from nltk.corpus import words
import re
import random

word_list = words.words()

left = 'qwertasdfgzxcvb'
right = 'yuiophjklnm'


myRe = re.compile('^(?:[{0}][{1}])+[{0}]?$|^(?:[{1}][{0}])+[{1}]?$'.format(left,right))

myWords = list(filter(myRe.search,word_list))


print((' '.join(myWords)))
print()

secureRandom = random.SystemRandom()
p=''
for i in range(5):
	p += secureRandom.choice(myWords) + ' '
print(p)
