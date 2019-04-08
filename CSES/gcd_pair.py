import math
def findMaxGCD(arr,n):
    high = max(arr)
    divisors = [0]*(high+1)
    for i in range(n):
        j = 1
        while(j <= (arr[i])**0.5):
            if(not arr[i]%j):
                divisors[j]+=1
                if(j**2 !=arr[i]):
                    divisors[arr[i]//j]+=1
            j+=1
    for i in range(high,0,-1):
        if(divisors[i]>1): return i

n = int(input())
print(findMaxGCD([int(x) for x in input().split()],n))
