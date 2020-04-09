mod = 10**9+7
h,w = map(int, input().split())

a = [input() for _ in range(h)]
dp = [[0]*w for _ in range(h)]

dp[0][0] = int(a[0][0] == '.')

for i in range(1,h):
    dp[i][0] = int(a[i][0] == ".")*dp[i-1][0]
for j in range(1,w):
    dp[0][j] = int(a[0][j] == ".")*dp[0][j-1]

for i in range(1, h):
    for j in range(1, w):
        dp[i][j] = int(a[i][j] == '.') * (dp[i - 1][j] + dp[i][j - 1])
        dp[i][j] %= mod
# for i in dp:
#     print(*i)

print(dp[h-1][w-1] % mod)


