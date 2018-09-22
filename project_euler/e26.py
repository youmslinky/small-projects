def lenRepeatReciprocal(d):
    #d is divisor
    #r is remainder
    #q is integer quotient
    #out is digits of quotient
    out = []
    qrPairs =[]
    r = 1
    q = 0

    while [q,r] not in qrPairs[:-1]:
        i=0
        while d > r:
            r *= 10
            i+=1
            if i>1:
                #print 'q:',0,'r:',r/10
                qrPairs.append([0,r/10])
                out.append(0)
        else:
            q = r/d
            r = r%d
            #print 'q:',q,'r:',r
            out.append(q)
            qrPairs.append([q,r])
            if r == 0:
                return 0
    #print 'exited because:',[q,r]
    return len(qrPairs[qrPairs.index([q,r]):])-1

d = 2
longest = 0

for i in range(1,1001):
    lenI = lenRepeatReciprocal(i)
    if lenI > longest:
        longest = lenI
        print i,longest
print longest

