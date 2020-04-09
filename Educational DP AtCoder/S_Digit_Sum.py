'*****************************************'
'    AUTHOR:         julianferres         '
'*****************************************'
import sys
def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

def base(n, k):
    out = []
    while n > 0:
        out.append(n % k)
        n //= k
    
    return out
print(base(30,4))