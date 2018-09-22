def swap(s):
    return ' '.join(reversed(s.split()))

s = raw_input('enter sentence: ')
print swap(s)
print s
