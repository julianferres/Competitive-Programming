n = int(input())
a = []
for i in range(n):
	s,e = map(int,input().split())
	a.append((e,s))
a.sort()

ans = 0
actEnd = 0
for m in a:
	e,s = m
	if(s>=actEnd):
		ans+=1
		actEnd=e
print(ans)
