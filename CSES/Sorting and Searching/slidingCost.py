from heapq import heappush, heappop, heappushpop
from collections import defaultdict


def fastio():
    import sys
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    def input(): return sys.stdin.readline().rstrip()
    sys.stdout = StringIO()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


fastio()

n, k = map(int, input().split())
a = [int(x) for x in input().split()]
lo, hi = [], []  # l es de mayores, y r de menores
medians = []

for i in range(k):
    if(len(lo) == len(hi)):
        heappush(hi, -heappushpop(lo, -a[i]))
    else:
        heappush(lo, -heappushpop(hi, a[i]))
medians.append(hi[0] if k & 1 else -lo[0])

to_remove = defaultdict(int)
for i in range(k, n):
    heappush(lo, -heappushpop(hi, a[i]))
    out_num = a[i-k]
    if(out_num > -lo[0]):
        heappush(hi, -heappop(lo))
    to_remove[out_num] += 1
    while lo and to_remove[-lo[0]]:
        to_remove[-lo[0]] -= 1
        heappop(lo)
    while to_remove[hi[0]]:
        to_remove[hi[0]] -= 1
        heappop(hi)
    medians.append(hi[0] if k & 1 else -lo[0])

cost = [0]*(n-k+1)
for i in range(n-k+1):
    for j in range(i, i+k):
        cost[i] += abs(medians[i]-a[j])
print(*cost)
