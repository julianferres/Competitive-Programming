import sys

def simular(n):
	cnt=0
	while(n!=1):
		cnt+=1
		if(n&1): n=3*n+1
		else: n//=2

	return cnt+1

for line in sys.stdin:
	a,b = map(int,input().split())
	m = 0
	for i in range(a,b+1):
		m = max(m,simular(i))
	print(a,b,m)
