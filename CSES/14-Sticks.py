# Sticks
#https://cses.fi/problemset/task/1074/
import statistics
n = int(input())
p = [int(x) for x in input().split()]

m = int(statistics.median(p))
ans = 0
for i in p:
	ans+= abs(m-i)
print(ans)

