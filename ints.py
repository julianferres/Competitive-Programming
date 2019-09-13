n = int(input())

q = 0
for i in range(n-2+1):
	q+= i*(n-2-i)

q = (n*q)//4
v = q + n

e = (q*4+n*(n-1))//2

f = e-v+2

print(f-1+n)



