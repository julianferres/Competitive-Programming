n, m, k = map(int, input().split())


fac = {0:1, 1:1}

for i in range(2,n+1):
	fac[i] = fac[i-1]*i

cum = 0


for i in range(m,n-k+1):
	cum += (fac[n]//(fac[i]*fac[n-i]))*((0.5)**n)

print("{0:.15f}".format(cum))