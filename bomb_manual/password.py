import re
groups = []
pattern = '^'
word_list = open('bomb_wordlist','r')
words = word_list.read()
for i in range(5):
    l = input(f'{i+1}-->')
    pattern += f'[{l}]'
    print(re.findall(pattern+'.*',words,re.MULTILINE))

