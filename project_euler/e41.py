import itertools
import ana

# max I've found yet 12356789

items = "123456789"
largest = 0;
for k in range(8,len(items)):
    for i in itertools.combinations(items,k):
        for j in itertools.permutations(i):
            print(j)
            n = int(''.join(i))
            if(ana.is_prime(n)):
                if(n>largest):
                    print("#########################new largest: ", n)
                    largest = n
