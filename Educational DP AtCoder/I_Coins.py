n = int(input())
p = [float(x) for x in input().split()]

dp = [[0]*(n+1) for _ in range(n)]  #dp[i][j] Prob of j heads in i tries
dp[0][1] = p[0]
dp[0][0] = 1-p[0]

for i in range(1, n):
    dp[i][0] = dp[i-1][0]*(1-p[i])
    for j in range(1,n + 1):
        if j <= i + 1:
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i])

sum = 0
for i in range(n + 1):
    if i > n - i:
        sum += dp[n-1][i]
print(sum)
            

            