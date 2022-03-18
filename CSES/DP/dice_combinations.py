from collections import deque
n = int(input())
M = 10**9+7
dp = deque([1,1,2,4,8,16,32])

if(n<=6):
	print(dp[n])
else:
	for i in range(7,n+1):
		dp.append(0)
		for j in range(1,7):
			dp[-1]+=dp[7-j]
		dp.popleft()
	print(dp[-1]%M)