N = 305
from collections import Counter
n = int(input())
a = [int(x) for x in input().split()]
c = Counter(a)

memo = [[[-1]*N for _ in range(N)] for __ in range(N)]
memo[0][0][0] = 0

def dp(a,b,c):
    if memo[a][b][c]>-0.5:
        return memo[a][b][c]

    z = n - (a+b+c)
    nz = n-z
    aux1, aux2, aux3 = 0, 0, 0
    if a:
        aux1 = a/(a+b+c)*dp(a - 1, b, c)
    if b:
        aux2 = b/(a+b+c)*dp(a + 1, b-1, c)
    if c:
        aux3 = c/(a+b+c)*dp(a, b+1, c-1)


    ans = nz/n*(aux1+aux2+aux3+1) + z/n
    ans *= n/nz
    memo[a][b][c] = ans
    return ans



print(dp(c[1],c[2],c[3]))
