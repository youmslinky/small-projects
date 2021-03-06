import math as m

def next_prime(n):
	if n == 0:
		return 2
	N = n+1
	while not is_prime(N):
		N += 1
	return N

def is_prime(n):
	for i in range(2, int(m.sqrt(n)+1) ):
		if n % i == 0:
			return False
	return True



# for i in range(100):
# 	if is_prime(i):
# 		print '{} is prime'.format(i)
# 	else:
# 		print '{} is NOT prime'.format(i)

print(next_prime(1000))