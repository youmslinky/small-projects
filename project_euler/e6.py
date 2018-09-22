square_of_sum = sum(range(1,101))**2
sum_of_squares = 0
for i in range(1,101):
    sum_of_squares += i**2
print square_of_sum - sum_of_squares
