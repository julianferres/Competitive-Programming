from collections import Counter,defaultdict
T = int(input())
for _ in range(T):
	K = int(input())
	cost = defaultdict(int)
	totalCost = 0
	for __ in range(K):
		char,value = input().split()
		cost[char]= int(value)
	M = int(input())
	for __ in range(M):
		a = input()
		for char in a:
			totalCost+= cost[char]
	print("{0:.2f}$".format(totalCost/100))


