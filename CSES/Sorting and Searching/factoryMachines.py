n,t = map(int,input().split())
k = sorted([int(x) for x in input().split()])

def isPossible(sec):
	aux = t
	for i in range(n):
		aux-= sec//k[i]
	return aux<=0

def solve():
	l = k[0]
	r = t*k[0]
	while(l<r):
		mid = (l+r)//2
		if(isPossible(mid) and not isPossible(mid-1)):
			return mid
		if(not isPossible(mid)):
			l = mid+1
		if(isPossible(mid-1)):
			r = mid-1
	return l

print(solve())



