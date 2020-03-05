# test out the examples
import ana

for n in range(41):
    p = n**2+n+41
    if ana.is_prime(p):
        print(f"{p} is prime")
    else:
        print(f"{p} is NOT prime")

print("\n\n\n**********")
print("bigger one")
print("**********")
for n in range(81):
    p = n**2-79*n+1601
    if ana.is_prime(p):
        print(f"{p} is prime")
    else:
        print(f"{p} is NOT prime")
