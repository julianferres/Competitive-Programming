# Playlist
# https://cses.fi/problemset/task/1141
n = int(input())
k = [int(x) for x in input().split()]
cur , m , prev = 1 , 1 , 0
visited = {i:-1 for i in k}
visited[k[0]] = 0

for i in range(1,n):
    prev = visited[k[i]]
    if(prev == -1 or (i-cur > prev)):
        cur+=1
    else:
        m = max(cur,m)
        cur = i - prev
    visited[k[i]] = i

print(max(m,cur))
