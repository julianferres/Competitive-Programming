MAXN = 21
MOD = 10**9+7
g = [[] for _ in range(MAXN)]
dp = [[0]*(MAXN) for _ in range(1 << MAXN)]


def dfs(state, v):
    aux = 0
    for u in g[v]:
        if state & (1 << u):
            if (dp[state - (1 << v)][u] > -1):
                aux += dp[state - (1 << v)][u]
            else:
                aux += dfs(state - (1 << v), u)
    dp[state][v] = aux % MOD
    return dp[state][v]


n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[b].append(a)
    # DFS al reves
for i in range(1 << MAXN):
    for j in range(MAXN):
        dp[i][j] = -1
        if (not (i & 1) or not i or not ((1 << j) & i)):
            dp[i][j] = 0

dp[1][0] = 1
dfs((1 << n) - 1, n - 1)
print(dp[(1 << n) - 1][n - 1] % MOD)
