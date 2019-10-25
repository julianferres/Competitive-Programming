# Permutation
# https://cses.fi/problemset/task/1070
n = int(input())
if(n==1): print(1)
elif(n==2 or n==3): print("NO SOLUTION")
else:
    d = []
    for i in range(2,n+1,2):
        d.append(i)
    for i in range(1,n+1,2):
        d.append(i)
    print(*d)
