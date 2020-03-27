# this is setup currently to generate length 19 for a certain website >_>
# maxlength and the retry until 19 are kinda redundant
# I'm using all length words from the dictionary
import csv
import json
import random
from keyboard_alternating_words import create_filter,classify_left_right

def random_phrase(words,length=5,maxLength=0):
    secureRandom = random.SystemRandom()
    pw = []
    last_pw = []
    # import pdb; pdb.set_trace()
    for _ in range(length):
        pw.append(secureRandom.choice(list(words)))
        # print(f"pwd:      {pw}")
        # print(f"length of pw: {len(''.join(pw))}")
        # print(f"last_pwd: {last_pw}")
        # print(f"length of last_pw: {len(''.join(last_pw))}")
        if maxLength > 0 and len(''.join(pw)) > maxLength:
            return last_pw
        last_pw = list(pw)
    return pw

words = {}
with open('google-books-common-words.txt') as tsvfile:
    reader = csv.DictReader(tsvfile, dialect='excel-tab')
    for row in reader:
        word = row['word'].lower()
        words[word] = { 'count':int(row['count']) }
# long_words = {}
# for word in words:
#     if len(word) >= 5:
#         long_words[word] = words[word]
# print(json.dumps(long_words,indent=4,sort_keys=True))
# print(f"there are {len(long_words)} words in long_words")
# print(f"there are {len(words)} words in long_words")
while True:
    phrase = ''
    #keep trying until we get a 19 length
    while len(''.join(phrase)) != 19:
        phrase = random_phrase(words,length=10,maxLength=20)
    print(f"length: {len(''.join(phrase))} --- {' '.join(phrase)}")
    n = input()
    if n != '':
        break

