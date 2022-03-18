from collections import deque
def bfs(ady, s, vis):
	q = deque([])
	q.append(s); vis[s] = True;
	while q:
		v = q.popleft()
		for u in ady[v]:
			if not vis[u]:
				vis[u] = True
				q.append(u)
n, m = map(int,input().split())
vis = {i:False for i in range(1,n+1)}
ady = {i:set() for i in range(1,n+1)}

for _ in range(m):
	a,b = map(int,input().split())
	ady[a].add(b); ady[b].add(a)
edges = []
act = 1
ans = 0
bfs(ady,1,vis)

for i in range(2,n+1):
	if not vis[i]:
		ans+=1
		edges.append((act,i))
		act = i
		bfs(ady,i,vis)

print(ans)
for i in edges: print(*i)
