M = 10**9+7

def sArit(l,r):
    n = r-l+1
    return n*(l+r)//2


n = int(input())
ans = 0
i = 1; minVal = n
while(i*i<=n):
    l = n//(i+1); r = n//i
    if(l>=r): continue
    ans+= i*(sArit(l+1,r))
    minVal = l
    ans%=M
    i+=1

for i in range(1,minVal+1):
    ans += i*(n//i)
    ans %= M

print(ans%M)


