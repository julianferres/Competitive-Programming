n,x = map(int,input().split())
c = [int(x) for x in input().split()]
d = [0 for i in range(x+1)]; d[0]=1
for e in c:
	for i in range(1,x+1):
		if(e<=i): d[i]=(d[i]+d[i-e])%1000000007
print(d[x])