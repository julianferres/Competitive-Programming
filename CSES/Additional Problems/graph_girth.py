
from math import inf


def floydWarshall(adyMatrix):
    "APSP problem, O(V^3)"
    v = len(adyMatrix)
    for k in range(v):
        for i in range(v):
            for j in range(v):
                if i == j and (g[i][k] == 1 or g[k][j] == 1):
                    continue
                else:
                    adyMatrix[i][j] = min(
                        adyMatrix[i][j], adyMatrix[i][k]+adyMatrix[k][j])


n, m = map(int, input().split())
g = [[inf]*n for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a][b] = g[b][a] = 1

floydWarshall(g)

for i in g:
    print(*i)
