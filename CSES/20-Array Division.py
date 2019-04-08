n , k = map(int,input().split())
a = sorted([int(x) for x in input().split()],reverse = True)
l = [[a[i]] for i in range(k)]
for i in range(k,n):
    l[2*k-1-i].append(a[i])
ans = float('-inf')
for i in l:
    ans = max(ans, sum(i))
print(ans)
