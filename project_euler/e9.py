def isTri(a,b,c):
    return a**2+b**2==c**2
for a in range(998):
    for b in range(998):
        c = 1000-a-b
        if isTri(a,b,c) and a<b<c:
            print a,b,c
            print a*b*c
