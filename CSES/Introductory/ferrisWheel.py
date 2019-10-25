# Ferris Wheel
# https://cses.fi/problemset/task/1090
n , x = map(int , input().split())
p = sorted([int(x) for x in input().split()])
ini , fin = 0 , n-1
ans = 0
while(ini<fin):
    if(p[fin]+p[ini] <= x):
        ini+=1
    fin-=1
    ans+=1
print(ans+int(ini==fin))
