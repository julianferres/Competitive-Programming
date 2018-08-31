def divsum(n):
	suma=0
	for i in range(1,n):
		if not n%i:
			suma+=i
	return suma
	

