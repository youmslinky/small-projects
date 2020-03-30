current_max = 0
for a in range(100):
    for b in range(100):
        s = str(a**b)
        current_sum = 0
        for n in s:
            current_sum += int(n)
        if current_sum > current_max:
            current_max = current_sum
            print(current_sum)


print(current_max)

# 3173034
# not correct: 3282376
