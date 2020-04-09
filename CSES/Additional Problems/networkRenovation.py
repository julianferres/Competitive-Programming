from collections import defaultdict, deque
n = int(input())
g = [set() for _ in range(n)]
d = [0]*n
deleted = [False]*n
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].add(b)
    g[b].add(a)
    d[a] += 1
    d[b] += 1


def deleteNodeOfDeg2(v):
    x, y = list(g[v])
    deleted[v] = True
    g[x].remove(v)
    g[y].remove(v)
    g[x].add(y)
    g[y].add(x)


def deleteLeaf(v):
    u = list(g[v])[0]
    if d[u] == 1:
        return
    deleted[v] = True
    g[u].remove(v)
    d[u] -= 1
    if(d[u] == 1):
        deleteLeaf(u)
        # deleteNodeOfDeg2(u)


for i in range(n):
    if d[i] == 2:
        deleteNodeOfDeg2(i)
leavesWithNei = []
for i in range(n):
    if not deleted[i] and d[i] == 1:
        leavesWithNei.append((list(g[i])[0], i))
leavesWithNei.sort()
leavesWithNei = deque(leavesWithNei)
s = []

while len(leavesWithNei) >= 2:
    u = leavesWithNei.pop()
    v = leavesWithNei.popleft()
    if u[0] == v[0]:
        leavesWithNei.appendleft(u)
        leavesWithNei.append(v)
        break
    s.append((u[1], v[1]))
    deleteLeaf(u[1])
    deleteLeaf(v[1])

remaining = n-sum(deleted)
#print("r", remaining)
rem = [i for i in range(n) if not deleted[i]]
if remaining == 2:
    u, v = rem
    s.append((u, v))
else:
    center = [i for i in rem if d[i] > 1][0]
    rem.remove(center)
    if not (len(rem) & 1):
        for i in range(len(rem)):
            if(not(i & 1)):

                s.append((rem[i], rem[i+1]))
    else:
        for i in range(len(rem)):
            if(not(i & 1) and i+1 < len(rem)):
                s.append((rem[i], rem[i+1]))
        s.append((rem[0], rem[-1]))
for i in range(len(s)):
    a, b = s[i]
    s[i] = (min(a, b), max(a, b))
s = list(set(s))
print(len(s))
for x in s:
    print(x[0]+1, x[1]+1)
