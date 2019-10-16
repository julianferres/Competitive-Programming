n = int(input())
r = [int(x) for x in input().split()]
pInv = [[0 for j in range(n)] for i in range(n)]
tri = lambda n: n*(n+1)//2

for i in range(n):
	for j in range(i+1,n):
		ri,rj = r[i],r[j]
		if(ri<=rj):
			pInv[i][j] = tri(ri-1)/(ri*rj)
		else:
			pInv[i][j] = (tri(rj)+rj*(ri-1-rj))/(ri*rj)

ans = 0
for i in range(n):
	ans+=sum(pInv[i])

print("{0:.6f}".format(ans))
