# Apartments
# https://cses.fi/problemset/task/1084
n , m , k = map(int, input().split())
a = sorted([int(x) for x in input().split()])
b = sorted([int(x) for x in input().split()])
aux_a , aux_b = 0 , 0
ans = 0
while(aux_b < len(b) and aux_a < len(a)):
    if(a[aux_a]<b[aux_b]-k):
        aux_a +=1
        continue
    elif(b[aux_b]-k <= a[aux_a]<= b[aux_b]+k):
        ans+=1
        aux_a+=1
        aux_b+=1
    else:
        aux_b +=1
print(ans)
