def zeta(s):
	n = len(s)
	z = [0]*n
	l,r = 0,0
	for i in range(1,n):
		if(i<=r): z[i] = min(r-i+1,z[i-l])
		while(i+z[i]<n and s[z[i]]==s[i+z[i]]):
			z[i]+=1
		if(i+z[i]-1>r):
			l=i
			r = i+z[i]-1
	return z
 
z = zeta(input())
n = len(z)
ans = [n]
for i in range(1,n):
	if(z[i]+i>=n):
		ans.append(i)
		continue
	if z[i]>=i:
		aux = i
		while(aux<n-i and z[aux]>=i):
			aux+=i
		if(aux>=n-i):
			if aux>=n or z[aux]+aux>=n:
				ans.append(i)

print(*sorted(ans))
