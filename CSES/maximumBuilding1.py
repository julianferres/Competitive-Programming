def maxAreaHistogram(n,A):
    if(len(A)==1):
        print(A[0])
    s = []
    maxarea = 0
    i = 0
    while(i<n):
        if(len(s)==0 or A[s[-1]]<=A[i]): s.append(i)
        else:
            while(len(s)>0 and A[s[-1]]>= A[i]):
                tp = s.pop()
                base = i if len(s)==0 else i-s[-1]-1
                h = A[tp]
                maxarea = max(base*h,maxarea)
            s.append(i)
        i+=1

    while(len(s)>0):
        tp = s.pop()
        base = i if len(s)==0 else i-s[-1]-1
        h = A[tp]
        maxarea = max(base*h,maxarea)
    return maxarea
        
n,m = map(int,input().split())
a = [input() for _ in range(n)]
dp = [[0]*m for i in range(n)]
for j in range(m):
    dp[0][j] = int(a[0][j]=='.')
for i in range(n):
    for j in range(m):
        if(a[i][j]=='.'):
            dp[i][j]=dp[i-1][j]+1

ans = 0
for i in range(n):
    ans = max(ans,maxAreaHistogram(m,dp[i]))
print(ans)