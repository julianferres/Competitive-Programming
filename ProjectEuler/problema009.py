def es_terna(a,b,c):
	return c**2==a**2+b**2
	
def recorrer():

	for i in range(1,1000):
		for j in range(1,1000-i):
			if es_terna(i,j,1000-i-j):
				return i,j,1000-i-j


