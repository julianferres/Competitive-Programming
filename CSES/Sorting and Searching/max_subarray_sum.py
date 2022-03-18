from math import inf
n = int(input())
a = [int(x) for x in input().split()]

actMax = -inf
actSum = 0
for i in range(n):
	actMax = max(actMax,actSum)
	if(actSum+a[i]<0):
		actSum=0
	else:
		actSum += a[i]
actMax = max(actMax,actSum)
if(max(a)<=0):
	actMax = max(a)
print(actMax)


