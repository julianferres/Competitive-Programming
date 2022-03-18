from heapq import heappush,heappop
x,n = map(int,input().split())
d = [int(x) for x in input().split()]
q = []
ans = 0
for i in d: heappush(q,i)

for i in range(n-1):
	f = heappop(q)
	s = heappop(q)
	ans+= f+s
	heappush(q,f+s)
print(ans)
