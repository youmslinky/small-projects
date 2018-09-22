import ana

mostFac = 1
longest = [1]
lenLongest = 1
t = 1
i = 2
found = 437580
while len(longest) < 500:
    can = ana.divisors(t)
    if len(can)>lenLongest:
        longest = can
        lenLongest = len(longest)
        mostFac = t
        print longest
        print t
        print 'len:',len(longest)
    t+=i
    i+=1
print longest
print t
print 'len:',len(longest)
