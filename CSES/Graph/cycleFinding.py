n, m = map(int, input().split())

e = []
for _ in range(m):
    a,b,c = map(int,input().split())
    e.append((a-1,b-1,c))
d, p = [0]*n, [0]*n
for i in range(n):
    x = -1
    for a,b,c in e:
        if d[a]+c<d[b]:
            p[b] = a
            d[b] = d[a]+c
            x = b #Al menos un d mejoro

if x==-1: #Ya en la ultima pasada no mejoro nada
    print("NO")

else:
    for i in range(n): 
        x = p[x]
    o = x
    a = [o]
    while p[x]!=o:
        x = p[x]
        a.append(x)
    a.append(o)
    a=reversed([x+1 for x in a])
    print("YES")
    print(*a)





