def find_missing(seq):
    diff = []
    for i in range(0,len(seq)-1):
        diff.append(abs(seq[i+1] - seq[i]))
    #for v in diff:
    print diff
    return seq[diff.index(max(diff))]+min(diff)

a = [1,2,3,4,6,7,8,9]
b = [2,4,8,10,12,14]
c = [-10,-9,-8,-6,-5,-4]
d = [6,5,4,2,1,0,-1]
print find_missing(d)
