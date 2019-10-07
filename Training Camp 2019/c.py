n = int(input())
a = [int(x) for x in input().split()]
b, c = [0]*n,[0]*n
c[n//2] = a[n//2]
def d():
	for i in range(n//2):
		if((a[i]+a[n-1-i])%2 != 0):
			print("NO")
			return
		
		
		c[i]= (a[i]+a[n-1-i])//2
		c[n-1-i] = c[i]
		b[i] = a[i]-c[i]
		b[n-1-i] = -b[i]
	
	print("YES")
	print(*b)
	print(*c)
	

d()
	