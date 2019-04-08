n = int(input())
if(n%4==1 or n%4==2):
    print("NO")
else:
    print("YES")
    if(not n%4):
        a , b = [] , []
        for i in range(1,n+1):
            if(i%4==0 or i%4==1): a.append(i)
            else: b.append(i)
    if(n%4 == 3):
        a , b = [1,2] , [3]
        for i in range(4,n+1):
            if(i%4==0 or i%4==3): a.append(i)
            else: b.append(i)
    print(len(a))
    print(*a)
    print(len(b))
    print(*b)
