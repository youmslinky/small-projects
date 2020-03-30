import sys

def fibonacci(n,fibs={}):
    #print n,len(fibs)
    #print fibs
    # eval(input())
    if n in [0, 1]:
        return n
    elif n in fibs:
        return fibs[n]
    else:
        fib = fibonacci(n - 1) + fibonacci(n - 2)
        fibs[n] = fib
        return fib

for i in range(20):
    print(fibonacci(i))
