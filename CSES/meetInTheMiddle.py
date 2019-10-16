from collections import defaultdict
def calsubarray(a,x,n,c,S):
	for i in range(1<<n):
		s = 0
		for j in range(n):
			if(i&(1<<j)): s+= a[j+c]
		if(s<=S): x[s]+=1


n, S = map(int,input().split())
a = [int(x) for x in input().split()]
X = defaultdict(int)
Y = defaultdict(int)
calsubarray(a,X,n//2,0,S)
calsubarray(a,Y,n-n//2,n//2,S)
sX,sY = 1<<(n//2),1<<(n-n//2)
ans = 0 
for i in X:
	if(S-i in Y): ans+=X[i]*Y[S-i]
print(ans)


