from heapq import heappush,heappop,heappushpop
from collections import defaultdict
n,k = map(int,input().split())
a = [int(x) for x in input().split()]
lo,hi = [],[] #l es de mayores, y r de menores
ans = []

for i in range(k):
	if(len(lo)==len(hi)):
		heappush(hi,-heappushpop(lo,-a[i]))
	else:
		heappush(lo,-heappushpop(hi,a[i]))
ans.append(hi[0] if k&1 else -lo[0])
to_remove =  defaultdict(int)

for i in range(k,n):
	heappush(lo,-heappushpop(hi,a[i]))
	out_num = a[i-k]
	if(out_num> -lo[0]): heappush(hi,-heappop(lo))
	to_remove[out_num]+=1
	while lo and to_remove[-lo[0]]:
		to_remove[-lo[0]] -=1
		heappop(lo)
	while to_remove[hi[0]]:
		to_remove[hi[0]]-=1
		heappop(hi)
	ans.append(hi[0] if k&1 else -lo[0])

print(*ans)




