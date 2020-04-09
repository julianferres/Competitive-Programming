s = input()
p = input()
n, m = len(s), len(p)

dp = [[None] * (m + 1) for _ in range(n + 1)]

for i in range(n + 1):
    for j in range(m + 1):
        if i == 0 or j == 0:
            # print(i,j)
            dp[i][j] = 0
        elif s[i - 1] == p[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

i, j = n, m
ans = []

while i and j:
    if s[i - 1] == p[j - 1]:
        ans.append(s[i - 1])
        i -= 1
        j -= 1
    elif dp[i - 1][j] > dp[i][j - 1]:
        i -= 1
    else:
        j -= 1

ans.reverse()
print("".join(ans))
        
    

