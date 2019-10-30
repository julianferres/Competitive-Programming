from math import log2
def rec(y,x):
	if(y==x): return 0
	y,x = min(x,y),max(x,y)
	if(y==1): return x-1
	gc2 = 2**int(log2(x))
	if(gc2==x): return x-y
	if(y>gc2): return rec(x-gc2,y-gc2)
	return gc2+rec(y,x-gc2)

y,x = map(int,input().split())
print(rec(y,x))