import timeit
M = 10**9+7
def modexp( x, y, p ):
	res = 1
	while(y>0):
		if(y & 1):
			res*= x
			res%=p
		y >>= 1
		x*= x
	return res%p

modinv = lambda a, m : modexp(a, m-2, m)
start = timeit.default_timer()
f = [1,1]
for i in range(2,10**6+1): f.append(f[-1]*i%M)

T = int(input())
for _ in range(T):
	a,b = map(int,input().split())
	print(f[a]*modinv(f[b],M)*modinv(f[a-b],M)%M)