from math import inf
n,m,k =map(int,input().split())
g = [[inf for _ in range(n)] for __ in range(n)]
for _ in range(m):
	a,b,c = map(int,input().split())
	g[a-1][b-1] = min(g[a-1][b-1],c)

def mul(a,b):
	r = [[0 for _ in range(n)] for __ in range(n)]
	for i in range(n):
		for j in range(n):
			r[i][j] = a[i][0]+b[0][j]
			for k in range(n):
				r[i][j] = min(r[i][j],a[i][k]+b[k][j])
	return r


def be(b,e):
	r = b
	while(e):
		if e&1:
			r=mul(b,r)
		b = mul(b,b)
		e>>=1
	return r

ans = be(g,k-1)
print(ans[0][n-1] if ans[0][n-1]<inf else -1)
