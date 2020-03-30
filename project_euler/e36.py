import ana

bin_base = bin(585)[2:]
print(ana.is_palindrome(bin_base))

sum = 0
for i in range(1000000):
    if ana.is_palindrome(bin(i)[2:]) and ana.is_palindrome(i):
            print(f"{i} is palindromic in both bases")
            sum += i

print(f"sum: {sum}")
