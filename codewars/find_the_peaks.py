
def pick_peaks(arr):
    out={}
    pos=[]
    peaks=[]
    for i,l in enumerate(arr[1:-1],1):
        if l > arr[i-1] and goes_down(arr[i:]):
            peaks.append(l)
            pos.append(i)
    out['pos']=pos
    out['peaks']=peaks
    return out

def goes_down(arr):
    height=arr[0]
    for l in arr:
        if l < height:
            return True
        if l > height:
            return False
    return False
