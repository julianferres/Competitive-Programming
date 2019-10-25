n = int(input())
x = [int(x) for x in input().split()]
s = set()
s.add(0)

for i in range(n):
	sadd = set()
	for j in s:
		sadd.add(x[i]+j)
	s|= sadd
print(len(s)-1)
print(*sorted(list(s))[1:])