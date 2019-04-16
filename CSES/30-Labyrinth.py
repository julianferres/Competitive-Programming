from collections import deque

def bfs(graph, start, goal):
    if start == goal:
        print([start])
        return
    queue = deque([start])

    # dict which holds parents, later helpful to retreive path.
    # Also useful to keep track of visited node
    parent = {}
    parent[start] = start

    while queue:
        currNode = queue.popleft()
        for neighbor in graph[currNode]:
            # goal found
            if neighbor == goal:
                parent[neighbor] = currNode
                return generate_path(parent, neighbor, start)
            # check if neighbor already seen
            if neighbor not in parent:
                parent[neighbor] = currNode
                queue.append(neighbor)
    return []

def generate_path(parent, goal, start):
    path = [goal]
    # trace the path back till we reach start
    while goal != start:
        goal = parent[goal]
        path.append(goal)
    path.reverse()
    return path

def get_ads(i,j,n,m,l):
	adjacent = set()
	if(i>0):
		if(l[i-1][j]!='#'): adjacent.add((i-1,j))
	if(j>0):
		if(l[i][j-1]!='#'): adjacent.add((i,j-1))
	if(i<n-1):
		if(l[i+1][j]!='#'): adjacent.add((i+1,j))
	if(j<m-1):
		if(l[i][j+1]!='#'): adjacent.add((i,j+1))
	return adjacent

n , m = map(int,input().split())
l = []
for i in range(n):
    l.append(input())

graph = {}
start , end  = 0 , 0 
for fila in range(n):
	for col in range(m):
		if(l[fila][col]=='#'): continue
		if(l[fila][col]=='A'): start = (fila,col)
		if(l[fila][col]=='B'): end = (fila,col)
		graph[(fila,col)] = get_ads(fila,col,n,m,l)

path = bfs(graph , start , end)
if(not len(path)):print("NO")
else:
	print("YES")
	ans = "" 
	print(len(path)-1)
	for i in range(len(path)-1):
		act , sig = path[i] , path[i+1]
		if(act[0]+1==sig[0]): ans+='D'
		elif(act[0]-1==sig[0]): ans+='U'
		elif(act[1]+1==sig[1]): ans+='R'
		else: ans+='L'
	print(ans)

