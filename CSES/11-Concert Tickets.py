# Ferris Wheel
# https://cses.fi/problemset/task/1090
from bisect import bisect_right
#def BinarySearch(a, x):
#    i = bisect_left(a, x)
#    if(a[i]==x):
#        return i
#    return (i-1) if i else -1

n , m = map(int , input().split())
h = sorted([int(x) for x in input().split()])
t = [int(x) for x in input().split()]

for x in t:
	i = bisect_right(h,x)
	if(i==0):
		print(-1)
		continue
	print(h[i-1])
	h.pop(i-1)
