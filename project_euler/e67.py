
tri = []
f = open("p067_triangle.txt")
for line in f:
    tri.append(map(int,line.split()))

def bestBot(tri):
    row = len(tri)-2
    columns = len(tri[row])
    newRow = []
    i=0
    for v in tri[row]:
        if tri[row+1][i] > tri[row+1][i+1]:
            newRow.append(tri[row+1][i]+v)
        else:
            newRow.append(tri[row+1][i+1]+v)
        i+=1
    return newRow
out = []
while len(tri)>1:
    newRow=bestBot(tri)
    tri.pop()
    tri[-1]=newRow
print tri
    
