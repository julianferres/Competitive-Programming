from collections import deque
from itertools import permutations
perm = list(permutations("123456789", 9))
for i in range(len(perm)):
    perm[i] = "".join(perm[i])
g = {i: [] for i in perm}

swaps = [[0, 1], [1, 2], [3, 4], [4, 5], [6, 7], [7, 8],
         [0, 3], [1, 4], [2, 5], [3, 6], [4, 7], [5, 8]]

for j in range(len(perm)):
    lx = perm[j]
    for i in swaps:
        a, b = min(i[0], i[1]), max(i[0], i[1])
        vx = lx[:a]+lx[b]+lx[a+1:b]+lx[a]+lx[b+1:]
        g[lx].append(vx)


def bfs(ady, s):
    vis = set()
    dist = {}

    q = deque([])
    q.append(s)
    vis.add(s)
    dist[s] = 0

    while q:
        v = q.popleft()
        for u in ady[v]:
            if u not in vis:
                vis.add(u)
                q.append(u)
                dist[u] = dist[v]+1
    return dist


d = bfs(g, '987654321')
a = []
for i in range(3):
    x = [x for x in input().split()]
    a.extend(x)
s = "".join(a)[::-1]
print(d[s])
