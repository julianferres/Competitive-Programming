import math
mod = 10**9+7
pre_computed = {}

def create_precomputed_table():
   pre_computed[0]=1
   pre_computed[1]=1
   for i in range(2, 5005):
      pre_computed[i] = i*pre_computed[i-1]
 
create_precomputed_table()

def modinv(a,p):
   return modexp(a,p-2,p)

def binomial(n, k):
    if n < k: return 0
    return (pre_computed[n] * modinv(pre_computed[n - k],mod) * modinv(pre_computed[k],mod)) % mod

M = 10**9+7
def modexp ( g, u, p ):
   s = 1
   while u != 0:
      if u & 1:
         s = (s * g)%p
      u >>= 1
      g = (g * g)%p;
   return s


a, b = map(int, input().split())

dp = [0]*(b+2)
dp[0] = a%M
dp[1] = (a*(a+1)//2)%M


for i in range(2,b+1):
   aux = 0
   for j in range(2,i+1+1):
      aux+= binomial(i+1,j)*dp[i+1-j]
   dp[i] = (modinv(i+1,M)*(modexp(a+1,i+1,M)-1-aux))%M


print(dp)
print(dp[b])