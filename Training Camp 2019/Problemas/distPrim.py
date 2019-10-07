import math

def is_prime(n):
	for i in range(2,int(math.sqrt(n))+1):
		if(n%i==0):
			return False
	return True



max_dist = 0
prev_prime = 2
for i in range(2,1000):
	if is_prime(i):
		if(i-prev_prime> max_dist):
			print(i)
			max_dist = i-prev_prime
			prev_prime = i


print("aaa:{}".format(max_dist))
