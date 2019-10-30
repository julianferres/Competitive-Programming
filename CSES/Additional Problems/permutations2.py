n = int(input())
a=[1,1,0,0,2]
for i in range(5,n+1):
	a.append(((i+1)*a[-1]-(i-2)*a[-2]-(i-5)*a[-3]+(i-3)*a[-4])%1000000007)
print(a[n])