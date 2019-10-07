def phi(n):
	result = n
	p=2
	while(p*p<=n):
		if(n%p==0):
			while(n%p == 0):
				n = n//p
			result -= result//p
		p+=1

	if(n>1):
		result-= result//n
	return result

def LcmSum(n):
	aux = 0
	d = 1 
	while(d*d<=n):
		if(n%d==0):
			if(d*d==n):
				aux+=phi(d)*d
			else:
				aux+=phi(d)*d
				aux+=phi(n//d)*(n//d)

		d+=1 

	return n*(aux+1)//2

T = int(input())
for _ in range(T):
	m = int(input())
	print(LcmSum(m))