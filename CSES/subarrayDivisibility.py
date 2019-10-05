from collections import defaultdict
n = int(input())
a = [0]+[int(x)%n for x in input().split()]
for i in range(1,n+1): a[i]+=a[i-1]
rems = defaultdict(int)
ans = 0
for act in a:
	if( act%n in rems): ans+= rems[act%n]
	rems[act%n]+=1

print(ans)
