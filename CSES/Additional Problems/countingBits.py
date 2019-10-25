import math
n = int(input())
 
def c(n):
    if(n==0): return 0
    if(n==1): return 1
    if(n==2): return 2
    if(n==3): return 4
    d = math.floor(math.log(n,2))
    return 2**(d)*d//2 +(n-2**(d)+1)+c(n%(2**d))
 
print(c(n))
