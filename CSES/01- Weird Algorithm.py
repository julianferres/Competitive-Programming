# Weird Algorithm
# https://cses.fi/problemset/task/1068
n = int(input())
d = []
while(n>1):
    d.append(n)
    if(not n%2):n//=2
    else: n = 3*n+1
d.append(1)
print(*d)
