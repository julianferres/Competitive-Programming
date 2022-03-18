n  = int(input())
dsum = 0
durations = []
for _ in range(n):
	a,d = map(int, input().split())
	dsum += d
	durations.append(a)
fsum = 0
durations.sort()
for i in range(n): fsum+= (n-i)*durations[i]
print(dsum-fsum)
