c = [[0 for i in range(601)] for i in range(101)]
for i in range(1,7):
	c[1][i]=1
for n in range(1,101):
	for x in range(601):
		for i in range(1,7):
			if(x-i<=0):
				continue
			c[n][x] += c[n-1][x-i]

n, a, b = map(int,input().split())

num = 0
for i in range(a,b+1):
	num+=c[n][i]
den = 6**n
print("{0:.6f}".format(num/den))

