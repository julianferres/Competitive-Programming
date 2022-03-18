from heapq import heappush, heappop
import sys
from collections import defaultdict
'*****************************************'
'    AUTHOR:         JULIAN FERRES        '
'    INSTITUITION:   FIUBA                '
'                                         '
'*****************************************'


def input(): return sys.stdin.readline().strip()


def MAP(): return map(int, input().split())


sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7


n, m, k = MAP()
g = {}

for i in range(m):
    a, b, c = MAP()
    if a-1 in g:
        if b-1 in g[a-1]:
            g[a-1][b-1] = min(c, g[a-1][b-1])
        else:
            g[a-1][b-1] = c
    else:
        g[a-1] = {b-1: c}

s, t = 0, n-1
count = [0]*n
B = [(0, s)]  # Ultimo nodo de un path y su valor actual
P = []
while B and count[n-1] < k:
    
    C, u = heappop(B)
    print("C: ",C, ",u:",u)
    count[u] += 1
    if u == t:
        P.append(C)
    if count[u] <= k:
        if u not in g:
            continue
        for v in g[u]:
            heappush(B, (C+g[u][v], v))

print(*P)
