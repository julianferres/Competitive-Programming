s = input()
seen = set()
def permute(a,l,r):
	if l==r:
		seen.add("".join(a))
	else:
		for i in range(l,r+1):
			a[l],a[i] = a[i],a[l]
			permute(a,l+1,r)
			a[l],a[i] = a[i],a[l]

permute(list(s),0,len(s)-1)
print(len(seen))
ans = sorted(list(seen))
for i in ans:
	print(i)
	
