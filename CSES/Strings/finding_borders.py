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
ans = []
for i in range(1,n):
	if(z[i]+i==n):
		ans.append(n-i)
print(*ans[::-1])
