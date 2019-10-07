from math import inf
n = int(input())
a = [input() for _ in range(n)]
MOD = 10**9+7
dp = [[0 for _ in range(n)] for __ in range(n)]
dp[0][0] = int(a[0][0]=='.')
for i in range(1,n):
	dp[i][0] = int(dp[i-1][0]*int(a[i][0]=='.'))
for j in range(1,n):
	dp[0][j] = int(dp[0][j-1]*int(a[0][j]=='.'))

for i in range(1,n):
	for j in range(1,n):
		dp[i][j] = int(a[i][j]=='.')*(dp[i][j-1]+dp[i-1][j])

print(dp[-1][-1]%MOD)