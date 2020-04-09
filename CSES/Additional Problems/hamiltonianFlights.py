from itertools import permutations
n,m = map(int, input().split())
edges = set()
for i in range(m):
    a,b = map(int, input().split())
    a-=1; b-=1;
    edges.add((a,b))
