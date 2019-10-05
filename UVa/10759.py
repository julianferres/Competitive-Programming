gcd = lambda a,b : a if b==0 else gcd(b,a%b)

c = [[0 for i in range(151)] for i in range(25)]
for i in range(1,7):
	c[1][i]=1
for n in range(2,25):
	for x in range(151):
		for i in range(1,7):
			if(x-i<=0):
				continue
			c[n][x] += c[n-1][x-i]

n,x = map(int,input().split())
while(n!=0 or x!=0):
	if(x>n*6):
		print(0)
	else:
		num = 0
		for i in range(x,6*n+1):
			num+=c[n][i]
		den = 6**n
		g = gcd(num,den)
		num//=g; den//=g
		if(den==1):
			print(num)
		else:
			print("{}/{}".format(num,den))


	n,x = map(int,input().split())



