'*****************************************'
'    AUTHOR:         julianferres         '
'*****************************************'
import sys
def input(): return sys.stdin.readline().strip()
MOD = 10 ** 9 + 7

def build():
    for i in range(n-1, 0, -1):
        t[i] = (t[i<<1]+ t[(i<<1)|1])%MOD
def modify(idx, val):
    idx+=n; t[idx] = val
    while(idx>1):
        t[idx>>1] = (t[idx] + t[idx^1])%MOD
        idx >>=1
def query(l, r):
    """Responde al intervalo [l,r)"""
    res = 0 #Se usa el neutro de la operacion
    l+=n ; r+=n

    while(l<r):
        if(l&1):
            res += t[l]
            l+=1
        if(r&1):
            r-=1
            res += t[r]
        l>>=1; r>>=1

    return res%MOD


n = int(input())
ans = 1
a = [0]*n; t = [0]*(2*n); m = {}
x = [int(x) for x in input().split()]
for i in range(n): a[i] = x[i]
x.sort()

for i in range(n):
    if not x[i] in m:
        m[x[i]] = len(m)
for i in range(n): a[i] = m[a[i]]
t[n+a[0]] = 1
build()
for i in range(1,n):
    aux = (query(0,a[i])+1)%MOD
    modify(a[i],(t[n+a[i]]+aux)%MOD)
    ans = (ans+aux)%MOD
print(ans)