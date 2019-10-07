import math
def power(x, y, p) : 
	res = 1	 
	x = x % p 

	while (y > 0) : 
		if ((y & 1) == 1) : 
			res = (res * x) % p 
		y = y >> 1 
		x = (x * x) % p 
		
	return res 
	
n, k, m = map(int, input().split())

tri = lambda n: n*(n+1)//2

q = (tri(n)-math.floor((n+1)/2))//2
j = math.ceil(tri(n)/3)

print(power(10000,96,97))

a = ( power(k,tri(n),m)* power(6,m-2,m)+3*power(k,q+math.floor((n+1)/2),m)* power(6,m-2,m)+2*power(k,j,m)* power(6,m-2,m))%m

print(a)




