from collections import defaultdict
n , x = map(int,input().split())
a = [0]+[int(x) for x in input().split()]
for i in range(1,n+1): a[i]+=a[i-1]
occ = defaultdict(int)
ans = 0
for i in range(n+1):
	act = a[i]
	if(act-x in occ): ans+= occ[act-x]
	occ[act]+=1

print(ans)
