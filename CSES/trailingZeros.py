n = int(input())
ans = 0
d = 1
while(5**d<=n):
	ans+=n//5**d
	d+=1
print(ans)
