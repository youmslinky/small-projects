from collections import Counter
from collections import OrderedDict
import re

def str_repeater(c,n):
    out = ''
    for i in range(n):
        out += c
    return out

def mix(s1, s2):
    s1cnt=Counter(re.sub('[^a-z]','',s1))
    s2cnt=Counter(re.sub('[^a-z]','',s2))
    s1dic=OrderedDict(reversed(sorted(list(s1cnt.items()),key=lambda x: x[1])))
    s2dic=OrderedDict(reversed(sorted(list(s2cnt.items()),key=lambda x: x[1])))
    
    out=[]
    for i in range(max(max(s1dic.values()),max(s2dic.values()))):
        out.append([])

    for k,v in list(s1dic.items()):
        if v >= 2:
            if k in s2dic:
                if s2dic[k] == v:
                    out[v-1].append('=:'+str_repeater(k,v)) 
                elif s2dic[k] > v:
                    out[s2dic[k]-1].append('2:'+str_repeater(k,s2dic[k])) 
                else:
                    out[v-1].append('1:'+str_repeater(k,v)) 
            else:
                out[v-1].append('1:'+str_repeater(k,v))
        else:
            del s1dic[k]

    for k,v in list(s2dic.items()):
        if k not in s1dic and v >= 2:
            out[v-1].append('2:'+str_repeater(k,v)) 

    outSorted=[]
    for arr in out:
        outSorted.append(sorted(arr))
    outSorted=reversed(outSorted)
    allOut = []
    for arr in outSorted:
        for element in arr:
            allOut.append(element)
    
    return '/'.join(allOut)

print(str_repeater('a',5))



print(mix("Are they here", "yes, they are here"))
print("2:eeeee/2:yy/=:hh/=:rr")
# Test.describe("Mix")
# Test.it("Basic Tests")
# Test.assert_equals(mix("Are they here", "yes, they are here"), "2:eeeee/2:yy/=:hh/=:rr")
# Test.assert_equals(mix("looping is fun but dangerous", "less dangerous than coding"), "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg")
# Test.assert_equals(mix(" In many languages", " there's a pair of functions"), "1:aaa/1:nnn/1:gg/2:ee/2:ff/2:ii/2:oo/2:rr/2:ss/2:tt")
# Test.assert_equals(mix("Lords of the Fallen", "gamekult"), "1:ee/1:ll/1:oo")
# Test.assert_equals(mix("codewars", "codewars"), "")
# Test.assert_equals(mix("A generation must confront the looming ", "codewarrs"), "1:nnnnn/1:ooooo/1:tttt/1:eee/1:gg/1:ii/1:mm/=:rr")