def decabin(n):
	binario=''
	while(n!=0):
		binario+=str(n%2)
		n=n//2
	return binario

def es_pal(n):
	cad=str(n)
	
	return cad==cad[::-1]


	


