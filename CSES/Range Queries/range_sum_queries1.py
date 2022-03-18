n, q = map(int,input().split())
a = [0]+[int(x) for x in input().split()]
for i in range(1,n+1): a[i]+=a[i-1]

for _ in range(q):
	l,r = map(int,input().split())
	print(a[r]-a[l-1])

