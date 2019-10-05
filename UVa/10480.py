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


def dfs(n, s, cap, visited):
    visited[s] = True
    for u in range(n):
        if (not visited[u] and cap[s][u]>0):
            dfs(n,u,cap,visited)




n,m = map(int,input().split())
while(n!=0 and m!=0):
    cap = [[0]*n for i in range(n)]
    aristas = set()
    for _ in range(m):
        a,b,w = map(int,input().split())
        cap[a-1][b-1] = w; cap[b-1][a-1] = w
        aristas.add((a-1,b-1)); aristas.add((b-1,a-1))
    input()
    g = Graph(cap)
    g.FordFulkerson(0,1)
    visited = [False]*n
    dfs(n,0,cap,visited)

    for i in range(n):
        for j in range(i+1,n):
            if(visited[i]!=visited[j] and (i,j) in aristas ):
                print(i+1,j+1)
    print("")
    n,m = map(int,input().split())
