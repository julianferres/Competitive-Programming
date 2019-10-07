dp = [[[0]*51 for _ in range(51)] for __ in range(51)]
pre_computed = {}

n, m = map(int, input().split())
a = list(map(int, input().split()))










print(dp[n][m][0])