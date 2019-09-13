n = int(input())
dp = [1 for i in range(n+1)]

for i in range(1,n+1):
	j = 1
	while(i-j>=0 and j<=6 and i-j<=n):
		dp[i]+=dp[i-j]
		j-=1



print(dp[-1])
