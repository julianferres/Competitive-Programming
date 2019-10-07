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

n,m = map(int,input().split())
a = [input() for _ in range(n)]

v = {}
for i in range(n): 
	for j in range(m): 
		if(a[i][j]=='.'): v[(i,j)] = False

ady = {i:set() for i in v}

for i in range(n-1):
	for j in range(m-1):
		if a[i][j]=='.' and a[i][j+1]=='.':
			ady[(i,j)].add((i,j+1))
			ady[(i,j+1)].add((i,j))
		if a[i][j]=='.' and a[i+1][j]=='.':
			ady[(i,j)].add((i+1,j))
			ady[(i+1,j)].add((i,j))
for i in range(n-1):
	if a[i][m-1]=='.' and a[i+1][m-1]=='.':
			ady[(i,m-1)].add((i+1,m-1))
			ady[(i+1,m-1)].add((i,m-1))
for j in range(m-1):
		if a[n-1][j]=='.' and a[n-1][j+1]=='.':
			ady[(n-1,j)].add((n-1,j+1))
			ady[(n-1,j+1)].add((n-1,j))

ans = 0
for s in v:
	if not v[s]:
		ans+=1
		bfs(ady,s,v)

print(ans)
