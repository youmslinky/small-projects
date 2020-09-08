def get_digit(num, p):
    # gets the pth digit of num
    num %= 10 ** (p + 1)
    num //= 10 ** p
    return num


def persistence(n):
    persistence_number = 0
    sn = str(n)
    while int(sn) >= 10:
        product = 1
        for d in sn:
            product *= int(d)
        sn = str(product)
        persistence_number += 1
    return persistence_number


p = [39, 3, 25, 999]

for d in p:
    print((d, persistence(d)))

# print persistence(39)
