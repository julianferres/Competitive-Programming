n,q = map(int,input().split())
val = [int(x) for x in input().split()]
ans = [0 for i in range(n)]
par = [0 for i in range(n)]
par[0] = -1
for i in range(n-1):
	a,b = map(int,input().split())
	a-=1; b-=1
	par[b] = a

nonleaves = set()
for i in par[1:]:
	nonleaves.add(i)

for i in range(n):
	if i in nonleaves:
		continue
	cum = val[i]
	ans[i]=cum
	aux = i
	while(aux!=-1):
		ans[aux]+=cum
		aux=par[aux]
print(ans)


for i in range(q):
	query = input().split()
	if(query[0]=='1'):
		s,x = query[1],query[2]
		print(s,x)




	else:
		print(ans[int(query[1])-1])
