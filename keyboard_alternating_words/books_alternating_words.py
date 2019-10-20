import csv
import json
import random
from keyboard_alternating_words import create_filter,classify_left_right

def random_phrase(words,length=5):
    secureRandom = random.SystemRandom()
    patterns = []
    # add from any pattern to start
    patterns.append(secureRandom.choice(['rr','rl','lr','ll']))
    for i in range(length-1):
        if patterns[-1][-1] == 'l':
            patterns.append(secureRandom.choice(['rr','rl']))
        else:
            patterns.append(secureRandom.choice(['lr','ll']))
        #import pdb; pdb.set_trace()
    #p.append(secureRandom.choice(list(words[secureRandom.choice(['rr','rl','lr','ll'])])))
    pw = []
    for p in patterns:
        pw.append(secureRandom.choice(list(words[p])))
    return ' '.join(pw)

myRe = create_filter();
words = {'rr':{},'rl':{},'lr':{},'ll':{}}
with open('google-books-common-words.txt') as tsvfile:
    reader = csv.DictReader(tsvfile, dialect='excel-tab')
    for row in reader:
        word = row['word'].lower()
        if myRe.match(word):
            for pattern in ['rr','rl','lr','ll']:
                if classify_left_right(word) == pattern:
                    words[pattern][word] = { 'count':int(row['count']) }
long_words = {'rr':{},'rl':{},'lr':{},'ll':{}}
for pattern in words:
    for word in words[pattern]:
        if len(word) >= 5:
            long_words[pattern][word] = words[pattern][word]
print(json.dumps(long_words,indent=4,sort_keys=True))
while True:
    print(random_phrase(long_words,length=5))
    n = input()
    if n != '':
        break

