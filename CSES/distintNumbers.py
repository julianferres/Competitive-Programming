n = int(input())
a = [int(x) for x in input().split()]
seen = set()
ans = 0
for i in a:
	if i in seen:
		continue
	ans+=1
	seen.add(i)
print(ans)
