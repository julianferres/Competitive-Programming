from collections import deque
from math import inf
class Graph:
    def __init__(self, cap):
        self.n = len(cap)
        self.cap = cap
    def bfs(self,s,t,parent):
        visited = [False]*(self.n)
        queue = deque([])
        queue.append(s); visited[s]=True
        while queue:
            u = queue.popleft()
            for ind,val in enumerate(self.cap[u]):
                if(not visited[ind] and val):
                    queue.append(ind)
                    visited[ind]=True
                    parent[ind] = u
        return visited[t]

    def FordFulkerson(self, source, sink):
        parent = [-1]*(self.n)
        max_flow = 0
        while self.bfs(source,sink,parent):
            path_flow = inf
            s = sink
            while(s!=source):
                path_flow = min(path_flow,self.cap[parent[s]][s])
                s = parent[s]
            max_flow += path_flow
            v = sink
            while(v!= source):
                u = parent[v]
                self.cap[u][v] -= path_flow
                self.cap[v][u] += path_flow
                v = parent[v]
        return max_flow
n = int(input())
cnt = 1
while(n!=0):
	s,t,m = map(int, input().split())
	cap = [[0]*n for i in range(n)]
	for _ in range(m):
		a,b,w = map(int, input().split())
		cap[a-1][b-1] += w; cap[b-1][a-1] += w
	g = Graph(cap)
	print("Network {}\nThe bandwidth is {}.".format(cnt,g.FordFulkerson(s-1,t-1)))
	print("")
	n = int(input())
	cnt+=1
