from math import inf
class Graph():
	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]
	def minDistance(self, dist, sptSet):
		m = float('inf')
		min_index = -1
		for v in range(self.V):
			if dist[v] < m and sptSet[v] == False:
				m = dist[v]
				min_index = v
		return min_index

	def dijkstra(self, src):

		dist = [inf] * self.V
		dist[src] = 0
		sptSet = [False] * self.V

		for cout in range(self.V):
			u = self.minDistance(dist, sptSet)
			sptSet[u] = True

			for v in range(self.V):
				if v in self.graph[u] and self.graph[u][v] > 0 and sptSet[v] == False and \
				dist[v] > dist[u] + self.graph[u][v]:
						dist[v] = dist[u] + self.graph[u][v]

		print(*dist)

n,m = map(int,input().split())
ady = {i:{} for i in range(n)}
for _ in range(m):
	a,b,c = map(int,input().split())
	if(b not in ady[a]):ady[a-1][b-1]=c
	else:
		ady[a][b]=min(ady[a][b],c)
	g=Graph(n)
	g.graph=ady
	g.dijkstra(0)

print(ady)
