M = 10**9+7
s = input()
last = [-1 for i in range(26)]
n = len(s)

dp = [-2 for i in range(n+1)]
dp[0] = 1

for i in range(1, n+1):
    dp[i] = 2*dp[i-1]
    dp[i] %= M
    if last[ord(s[i-1])-ord('a')] != -1:
        dp[i] -= dp[last[ord(s[i-1])-ord('a')]]
        dp[i] %= M
    last[ord(s[i-1])-ord('a')] = i-1

print((dp[n]-1) % M)
