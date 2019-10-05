T = int(input())
a = []
for _ in range(T):
	a.append(int(input()))

dp = [True]*(T+1)
for i in range(T-1,-1,-1):
	if(i+a[i]+1>T):
		dp[i]=False
	else:
		dp[i] = dp[i+a[i]+1]

ans = []
for i in range(T+1):
	if(dp[i] and i>0):
		print(i)
