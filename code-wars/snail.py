array1 = [[1,2,3],
         [4,5,6],
         [7,8,9]]
expected = [1,2,3,6,9,8,7,4,5]
        


    

def snail(array):  
    size=len(array[0])

    if len(array[0]) == 0:
        return []
    if size == 1:
        return array[0]

    d='r'
    row=0
    col=0
    out=[array[row][col]]

    pathLengths = [size-1 for i in range(3)]
    for i in reversed(list(range(1,size-1))):
        pathLengths.append(i)
        pathLengths.append(i)

    for length in pathLengths:
        for i in range(length):
            if d=='r':
                col+=1
            elif d=='l':
                col-=1
            elif d=='u':
                row-=1
            elif d=='d':
                row+=1
            out.append(array[row][col])
        if d=='r':
            d='d'
        elif d=='d':
            d='l'
        elif d=='l':
            d='u'
        elif d=='u':
            d='r'
    return out



print((snail(array1)))
print(expected)