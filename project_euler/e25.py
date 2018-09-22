fib = [1,1]
i = 2
while len(str(fib[-1])) < 1000:
    fib.append(fib[-1]+fib[-2])
    i+=1
    print fib[-1],i
