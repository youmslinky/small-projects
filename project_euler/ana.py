import math
def anagrams(word, words):
    word = ''.join(sorted(word))
    return filter(lambda w: ''.join(sorted(w)) == word, words)

def pos(nums):
    return filter(lambda x: x>=0, nums)
    
def spin_words(sentence):
    return ' '.join(map(lambda w: w[::-1] if len(w)>=5 else w, sentence.split()))

def to_weird_case(string):
    strings = string.split()
    outList = []
    for word in strings:
        convertedList = []
        for i,c in enumerate(word):
            if i%2==0:
                convertedList.append(c.upper())
            else:
                convertedList.append(c.lower())
        outList.append(''.join(convertedList))
                
    return ' '.join(outList)

def is_prime(num):
    if num == 0 or num == 1:
        return False
    num = abs(num)
    for i in xrange(2,num/2+1):
        if num%i == 0:
            return False
    return True

def num(s):
    try:
        return int(s)
    except ValueError:
        return float(s)

def calc(expr):
    ex = expr.split()
    for c in ex:
       pass 
def fib(n):
    out = [1,1]
    for v in range(0,n):
        out.append(out[v]+out[v+1])
    return out

def factors(n):
    out = []
    i = 2
    while n > 1:
        if n%i==0:
            out.append(i)
            n = n/i;
            i = 2;
        else:
            i += 1
    return out

def is_palindrome(n):
    n = list(str(n))
    if len(n)%2==0:
        front = n[:len(n)/2]
    else:
        front = n[:len(n)/2+1]
    back = n[len(n)/2:]
    return front == list(reversed(back))

def divisors(n):
    out = []
    for v in range(1,int(math.sqrt(n))):
        if n%v==0:
            out.append(v)
    out.append(n)
    return out
