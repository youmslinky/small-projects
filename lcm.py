def lcm(a, b):
    aa = a
    bb = b
    while True:
        if a == b:
            return a
        if a > b:
            b += bb
        else:
            a += aa


print((lcm(192, 25)))
