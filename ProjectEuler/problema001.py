def suma (fin):
	
	suma=0
	
	for n in range(1, fin):
		if ((n%3 == 0) or (n%5 == 0)):
			suma+= n
		
		
		
	print (suma)
		
suma(1000)
