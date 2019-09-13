n = int(input())
a = sorted([[int(x) for x in input().split()] for _ in range(n)])


ax = [a[i][0] for i in range(n)]
ay = sorted([a[i][1] for i in range(n)])


cnt = 0


#1 
aux = 1
for i in range(n-1):
	if(ax[i]==ax[i+1]):
		aux+=1

	else:
		cnt+= aux*(aux-1)//2
		aux= 1
cnt+= aux*(aux-1)//2


aux = 1
for i in range(n-1):
	if(ay[i]==ay[i+1]):
		aux+=1

	else:
		cnt+= aux*(aux-1)//2
		aux= 1
cnt+= aux*(aux-1)//2


aux = 1
for i in range(n-1):
	if(a[i]==a[i+1]):
		aux+=1

	else:

		cnt-= aux*(aux-1)//2
		aux= 1
cnt-= aux*(aux-1)//2

print(cnt)