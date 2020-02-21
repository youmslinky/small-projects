from bisect import bisect_left
from decimal import Decimal
import math

def eng_string( x, format='%s', si=False):
    '''
    Returns float/int value <x> formatted in a simplified engineering format -
    using an exponent that is a multiple of 3.

    format: printf-style string used to format the value before the exponent.

    si: if true, use SI suffix for exponent, e.g. k instead of e3, n instead of
    e-9 etc.

    E.g. with format='%.2f':
        1.23e-08 => 12.30e-9
             123 => 123.00
          1230.0 => 1.23e3
      -1230000.0 => -1.23e6

    and with si=True:
          1230.0 => 1.23k
      -1230000.0 => -1.23M
    '''
    sign = ''
    if x < 0:
        x = -x
        sign = '-'
    exp = int( math.floor( math.log10( x)))
    exp3 = exp - ( exp % 3)
    x3 = x / ( 10 ** exp3)

    if si and exp3 >= -24 and exp3 <= 24 and exp3 != 0:
        exp3_text = 'yzafpnum kMGTPEZY'[ ( exp3 - (-24)) / 3]
    elif exp3 == 0:
        exp3_text = ''
    else:
        exp3_text = 'e%s' % exp3

    return ( '%s'+format+'%s') % ( sign, x3, exp3_text)

def fexp(number):
    (sign, digits, exponent) = Decimal(number).as_tuple()
    return len(digits) + exponent - 1

def fman(number):
    return Decimal(number).scaleb(-fexp(number)).normalize()

def take_2_closest(myList, myNumber):
    """
    Assumes myList is sorted. Returns 2 closest value to myNumber.

    If two numbers are equally close, return the smallest number.
    """
    pos = bisect_left(myList, myNumber)
    if pos == 0:
        return (myList[0],0)
    if pos == len(myList):
        return (myList[-1],-1)
    before = myList[pos - 1]
    after = myList[pos]
    if after - myNumber < myNumber - before:
        return [after,before]
    else:
        return [after,before]

def E96():
    return [ round(10**(n/96),2) for n in range(96) ]

def closest_value(v,standard_values=E96()):
    mantissa = fman(v)
    exponent = fexp(v)
    # import pdb; pdb.set_trace()
    # for n in take_2_closest(standard_values,float(mantissa)):
    #     print((n * 10**exponent))
    return [n * 10**exponent for n in take_2_closest(standard_values,float(mantissa))]

# for n in [2*x/100 for x in range(1,100)]:
#     print(f"closest E96 value to {n} is {closest_value(float(n))}")

while True:
    n = input()
    if n == 'q':
        break
    for i in closest_value(float(n)):
        print(eng_string(i,si=True))
