def CeilIndex(A, l, r, key): 

	while (r - l > 1): 
	
		m = l + (r - l)//2
		if (A[m] >= key): 
			r = m 
		else: 
			l = m 
	return r 

def LongestIncreasingSubsequenceLength(A, size): 
	tailTable = [0 for i in range(size + 1)] 
	len = 0  

	tailTable[0] = A[0] 
	len = 1
	for i in range(1, size): 
	
		if (A[i] < tailTable[0]): 
			tailTable[0] = A[i] 

		elif (A[i] > tailTable[len-1]): 
			tailTable[len] = A[i] 
			len+= 1
		else: 
			tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i] 
		

	return len

n = int(input())
arr = [int(x) for x in input().split()]
print(LongestIncreasingSubsequenceLength(arr,n))
