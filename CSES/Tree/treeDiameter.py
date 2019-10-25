from collections import deque
def bfs(ady, s):
	vis = set()
	dist = {}
	q = deque([])
	q.append(s); vis.add(s); dist[s]=0

	while q:
		v = q.popleft()
		for u in ady[v]:
			if u not in vis:
				vis.add(u)
				q.append(u)
				dist[u] = dist[v]+1
	return dist


n = int(input())
t = {i:set() for i in range(n)}
for _ in range(n-1):
	a,b = map(int,input().split())
	t[a-1].add(b-1); t[b-1].add(a-1)

dist = bfs(t,0)
new_src = 0
M = 0
for i in dist:
	if(dist[i]>M):
		M=dist[i]; new_src=i
dist = bfs(t,new_src)
ans = 0
for i in dist: ans=max(ans,dist[i])
print(ans)