n = int(input())
a = sorted([int(x) for x in input().split()])
dif = sorted([a[2*i+1]-a[2*i] for i in range(n//2)])

ans = 0
s = sum(dif)
if(s==0):
	print(-1)
else:
	cum = 0
	for i in dif:
		if(cum+i<s-(cum+i)):
			ans+=1
			cum+=i
	print(ans)	

