def cuads(a,b,x):
	return x**2+a*x+b
	

def es_primo(numero):
	for i in range(2,int(numero**0.5)+1):
		if not numero%i:
			return False
	return True

def alcance_pol( a , b ):
	x=0
	if cuads(a,b,x)>1:
		while es_primo(cuads(a,b,x)):
			x+=1
	
	return x , a , b
	

		
