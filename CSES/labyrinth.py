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

n,m = map(int,input().split())
a = [input() for _ in range(n)]

v = {}
for i in range(n): 
	for j in range(m): 
		if(a[i][j]!='#'): v[(i,j)] = False

ady = {i:set() for i in v}

for i in range(n-1):
	for j in range(m-1):
		if a[i][j]!='#' and a[i][j+1]!='#':
			ady[(i,j)].add((i,j+1))
			ady[(i,j+1)].add((i,j))
		if a[i][j]!='#' and a[i+1][j]!='#':
			ady[(i,j)].add((i+1,j))
			ady[(i+1,j)].add((i,j))
for i in range(n-1):
	if a[i][m-1]!='#' and a[i+1][m-1]!='#':
			ady[(i,m-1)].add((i+1,m-1))
			ady[(i+1,m-1)].add((i,m-1))
for j in range(m-1):
		if a[n-1][j]!='#' and a[n-1][j+1]!='#':
			ady[(n-1,j)].add((n-1,j+1))
			ady[(n-1,j+1)].add((n-1,j))
A,B = None, None
for i in range(n):
	for j in range(m):
		if(a[i][j]=='A'): A = (i,j)
		if(a[i][j]=='B'): B = (i,j)


path = SSSP(ady,A,B)
ans = []
for x in range(len(path)-1):
	i,j = path[x]
	ib,jb = path[x+1]
	if(ib==i+1): ans.append("D")
	elif(ib==i-1): ans.append("U")
	elif(jb==j+1): ans.append("R")
	else: ans.append("L")
if(len(ans)>0):
	print("YES")
	print(len(ans))
	print("".join(ans))
else:
	print("NO")
