import ana 
def is_divBy(n,s):
    for d in s:
        if n%d!=0:
            return False
    return True

need = range(1,21)
current = []
n = 1

while not is_divBy(n,need):
    if n%100000==0:
        print n
    n+=1
print
print n
