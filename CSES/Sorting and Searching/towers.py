from bisect import bisect_right

def find_gt(a, x):
	'Find leftmost value greater than x'
	i = bisect_right(a, x)
	return i if i != len(a) else -1

n = int(input())
k = ([int(x) for x in input().split()])

towers = []

for element in k:
	index = find_gt(towers,element)
	if(index==-1):
		towers.append(element)
	else:
		towers[index] = element

print(len(towers))
