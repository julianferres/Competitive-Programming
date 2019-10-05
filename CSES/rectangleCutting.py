import timeit
from math import inf,gcd

a,b = map(int,input().split())
a,b = min(a,b),max(a,b)

dp = [[None for _ in range(b+1)] for __ in range(a+1)]
for idx in range(1,a+1): dp[idx][idx] = 0
#for x in dp: print(*x)

def rec(a,b):
	g = gcd(a,b); a//=g; b//=g;
	a,b = min(a,b),max(a,b)
	if dp[a][b] is not None:
		return dp[a][b]
	if(a<1):
		dp[a][b] = in
		return inf
	if(a==1):
		dp[a][b] = b-1
		return dp[a][b]
	m = inf
	for i in range(1,b//2+1):
		m = min(m, 1+rec(i,a)+rec(b-i,a))
	for j in range(1,a//2+1):
		m = min(m, 1+rec(a-j,b)+rec(j,b))
	dp[a][b] = m
	return dp[a][b]
print(rec(a,b))


# Ver porque puede ser dp optimization