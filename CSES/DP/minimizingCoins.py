from math import inf
import sys
sys.setrecursionlimit(10**6)
n, x = map(int, input().split())
c = [int(x) for x in input().split()]

memo = {}

def rec(x,i):
	if((x,i) in memo):
		return memo[(x,i)]
	if(i<0 and x!=0):
		memo[(x,i)] = inf
		return inf
	if(i<0 and x==0):
		memo[(x,i)] = 0
		return 0
	if(x<0):
		memo[(x,i)] = inf
		return inf
	memo[(x,i)] = min( 1+rec(x-c[i],i-1),rec(x,i-1),1+rec(x-c[i],i))
	return memo[(x,i)]

print(rec(x,n-1))