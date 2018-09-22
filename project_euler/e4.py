import ana
largest=0
pair=[0,0]
for i in range(0,1000):
    for j in range(0,1000):
        k=j*i
        if k>largest and ana.is_palindrome(k):
            largest = k
            pair=[i,j]
print largest
print pair

