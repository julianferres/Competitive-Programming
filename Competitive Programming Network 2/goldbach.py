def prime(n):
	i = 2
	while(i*i<=n):
		if(n%i==0): return False
		i+=1
	return True


while(True):

	n = input()
	if(not n): break
	n = int(n)
	if(n==2): print(1)
	elif(n%2==0): print(2)
	elif(prime(n)): print(1)
	elif(prime(n-2)): print(2)
	else: print(3)
