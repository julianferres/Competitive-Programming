for i in range(1,100):
	j = 1
	if(i%2==0 or i%5==0):
		print("{}: -1".format(i))
		continue
	while((10**j-1)//9 % i != 0):
		j+=1
	print("{}: {}".format(i,j))