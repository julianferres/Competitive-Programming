n = int(input())
a = [int(x) for x in input().split()]
m = int(input())
b = [int(x) for x in input().split()]

a = sorted(a)
b = sorted(b)

idx_a = 0
idx_b = 0
cnt = 0
while(idx_a < n and idx_b < m):

	if( abs(a[idx_a]-b[idx_b]) <= 1):
		idx_a+=1
		idx_b+=1
		cnt+=1

	elif(a[idx_a]>b[idx_b]):
		idx_b+=1
	else:
		idx_a+=1

print(cnt)