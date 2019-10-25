from collections import Counter
s = input()
c = Counter(s)
amountodds = 0
for i in c:
	if(c[i]&1): amountodds+=1

if(amountodds>1):
	print("NO SOLUTION")
else:
	l = ""
	odd = ""
	for i in c:
		if(c[i]&1):
			odd = i
		l = l + i*(c[i]//2)
	print(l+odd+l[::-1])

