MOD = 10**9+7
def prefixFunction(s):
	n = len(s)
	pi = [0 for _ in range(n)]
	
	for i in range(1,n):
		j = pi[i-1]
		while(j>0 and s[i]!=s[j]):
			j = pi[j-1]
		if(s[i]==s[j]): j+=1
		pi[i] = j

	return pi
def modexp(x, y, p):
	res = 1
	while(y>0):
		if(y & 1):
			res*= x
			res%=p
		y >>= 1
		x*= x

	return res%p

n = int(input())
s = input()
m = len(s)
pref = prefixFunction(s)
prefsuf = set()
aux = pref[-1]
while(aux>0):
	prefsuf.add(aux)
	aux = pref[aux-1]
print(pref)
print(prefsuf)

ans = (n-m+1)*modexp(26,n-m,MOD)


for i in range(n-m):
	for j in prefsuf:
		if(i+m+m-j<=n):
			ans-= modexp(26,n-2*m+j,MOD)
	ans%=MOD
	if(n-1-i-m+1>=m): #Entra otra m atras
		ans-= (n-1-i-m+1-m)*modexp(26,n-2*m,MOD)
	ans%=MOD	

print(ans) if(n>=m) else print(0)