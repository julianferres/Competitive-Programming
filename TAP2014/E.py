from collections import deque
A,N = map(int,input().split())
from math import inf
a = []
for i in range(A):
	a.append(list(map(int,input().split()))[1:])

dist = {i:inf for i in range(1,N+1)}
v = {i:[] for i in range(1,N+1)}
lvisto = [False]*A
dist[1]=0

for i in range(A):
	for j in a[i]:
		v[j].append(i)

q = deque([])
q.append(1)
dist[1]=0
while(len(q)>0):
	first = q.popleft()
	for lista in v[first]:
		if(lvisto[lista]==False):
			lvisto[lista] = True
			for i in a[lista]:
				if(dist[i]==inf):
					q.append(i)
				dist[i] = min(dist[i],dist[first]+1)




D = 0
M = -inf
S = 0
for i in dist:
	if(dist[i]<inf):
		D+=1
		S+=dist[i]
		M = max(dist[i],M)

print(D,M,S)