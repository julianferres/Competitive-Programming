# Increasing Array
# https://cses.fi/problemset/task/1094
n = int(input())
d = [int(x) for x in input().split()]
turns = 0

for i in range(1,n):
    if(d[i]>=d[i-1]):continue
    turns+= (d[i-1]-d[i])
    d[i] = d[i-1]
print(turns)
