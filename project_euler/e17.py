words={
        0:'',
        1:'one',
        2:'two',
        3:'three',
        4:'four',
        5:'five',
        6:'six',
        7:'seven',
        8:'eight',
        9:'nine',
        10:'ten',
        11:'eleven',
        12:'twelve',
        13:'thirteen',
        14:'fourteen',
        15:'fifteen',
        16:'sixteen',
        17:'seventeen',
        18:'eighteen',
        19:'nineteen',
        20:'twenty',
        30:'thirty',
        40:'forty',
        50:'fifty',
        60:'sixty',
        70:'seventy',
        80:'eighty',
        90:'ninety',
        100:'hundred',
        1000:'thousand'
        }
        
def intToEnglish(n):
    out = ''
    if n==1000:
        return "onethousand"
    if n>=100:
        out += words.get(n/100)
        out += 'hundred'
        n %= 100
        if n>0:
            out += 'and'
    if n>=20:
        out += words.get((n/10)*10)
        out += words.get(n%10)
        return out
    if n<20:
        out += words.get(n)
    return out

print 342,len(intToEnglish(342))
print 115,len(intToEnglish(115))
tot = 0
for i in range(1,1001):
    tot += len(intToEnglish(i))
print tot
