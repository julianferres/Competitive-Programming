from math import inf
n,a,b = map(int,input().split())
arr = [int(x) for x in input().split()]

actMax = -inf
actSum = 0
l = 0
for i in range(n):
	l+=1
	if(a<=l and l<=b): actMax = max(actMax,actSum)
	if(actSum+arr[i]<0):
		actSum=0
		l = 0
	else:
		actSum += arr[i]
if(a<=l and l<=b): actMax = max(actMax,actSum)
#if(max(a)<=0):
#	actMax = max(a)
print(actMax)


