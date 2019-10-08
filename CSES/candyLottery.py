n, k = map(int,input().split())
cum = 0
for i in range(1,k): cum+= i**n
print("{0:.6f}".format((k**(n+1)-cum)/k**n))