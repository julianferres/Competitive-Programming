# Number Spiral
# https://cses.fi/problemset/task/1071
q = int(input())
for _ in range(q):
    y , x = map(int, input().split())
    m = max(x,y)-1
    if(m%2): x , y = y , x
    print(m**2+(x-1)+1+m+1-y)
