import math
primes = []


def is_prime(n):
	for i in range(2,int(n**0.5)+1):
		if(n%i == 0):
			return False
	return True

for i in range(2,1000):
	if is_prime(i):
		primes.append(i)

def find_prime(n):
	"""Encuentra el mayor primo que divide a n!"""
	for i in primes[::-1]:
		if( n>= i and n%i==0):
			return i


def fact(n,First):
	if(n==1):
		return [1]
	k = find_prime(n)
	while(math.factorial(k)<= n):
		if(First and math.factorial(k)==n):
			return False
		fac = False
		if(n%math.factorial(k)==0):
			fac = fact(n//math.factorial(k),False)
		if(fac):
			return([k]+fac)
		k+=1
	return False

out = []
for i in range(1000):
	f = fact(math.factorial(i),True)
	if(f):
		out.append(f[::-1][1:])
	else:
		out.append([0])

print(out)

"""
n = int(input())
f = fact(math.factorial(n),True)
if(f):
	print(*f[::-1][1:])
else:
	print("No solution.")
"""


