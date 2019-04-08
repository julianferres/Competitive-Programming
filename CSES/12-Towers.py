from bisect import bisect_right
import heapq

n = int(input())
k = ([int(x) for x in input().split()])
topes = heapq.heapify([k[0]])
print(topes)
ans = 1
for val in k:
	print(topes)
	idx = bisect_right(list(topes),val)
	if(idx==len(list(topes))):
		heapq.heappush(topes,val)
		ans+=1
	else:
		topes[idx] = val
print(ans)



    
