T = int(input())

def solve(n,a):
	m = n+1
	ans = 0
	for i in range(n):
		if(a[i]<m):
			ans+=1
			m = a[i]
	print(ans)


for _ in range(T):
	n = int(input())
	a = [int(x) for x in input().split()]
	solve(n,a)