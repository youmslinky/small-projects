from collections import OrderedDict as od

b=[]

def hamming(n):
    for i in range(10):
        for j in range(10):
            for k in range(10):
            	num=2**i * 3**j * 5**k
            	#print i,j,k,'num:',num
            	#raw_input()
                b.append(num)
    return sorted(list(od.fromkeys(b)))[n-1]

hamming(10)
print((sorted(list(od.fromkeys(b)))))