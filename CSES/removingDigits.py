from math import inf
import sys
sys.setrecursionlimit(10**6)

def solve(n):
	if(n==0): 
		dp[0] = 0
		return 0
	if(n<10): 
		dp[n] = 1
		return 1
	if(dp[n]!=-1): return dp[n]
	m = inf
	for c in str(n):
		if(c!='0'):
			m = min(m,1+solve(n-int(c)))
	dp[n] = m
	return m

n = int(input())
dp = [-1 for _ in range(n+1)]

print(solve(n))