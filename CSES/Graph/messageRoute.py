from collections import deque
def bfs(ady, s):
	vis = set()
	parent = {}; dist = {}

	q = deque([])
	q.append(s); vis.add(s); parent[s]=-1; dist[s]=0

	while q:
		v = q.popleft()
		for u in ady[v]:
			if u not in vis:
				vis.add(u)
				q.append(u)
				dist[u] = dist[v]+1
				parent[u] = v
	return vis,parent,dist

def SSSP(ady, src, dst):
	"""Single-source shortest path"""
	vis, par , dist = bfs(ady,src)
	path = []
	if(dst not in vis): return path
	while(dst!=src):
		path.append(dst)
		dst = par[dst]
	path.append(src)
	return path[::-1]

n, m = map(int,input().split())
vis = {i:False for i in range(1,n+1)}
ady = {i:set() for i in range(1,n+1)}

for _ in range(m):
	a,b = map(int,input().split())
	ady[a].add(b); ady[b].add(a)

path = SSSP(ady,1,n)

print(len(path)) if len(path) else print("IMPOSSIBLE")
if(len(path)):
	print(*path)
