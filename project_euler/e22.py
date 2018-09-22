letters={'A':1,
	'B':2,
	'C':3,
	'D':4,
	'E':5,
	'F':6,
	'G':7,
	'H':8,
	'I':9,
	'J':10,
	'K':11,
	'L':12,
	'M':13,
	'N':14,
	'O':15,
	'P':16,
	'Q':17,
	'R':18,
	'S':19,
	'T':20,
	'U':21,
	'V':22,
	'W':23,
	'X':24,
	'Y':25,
	'Z':26
    }

f = open("p022_names.txt")
names=f.read().translate(None,'"').split(',')
names.sort()
i=1
total = 0
for name in names:
    total += i*sum(map(lambda c: letters.get(c),list(name)))
    i+=1
print total
