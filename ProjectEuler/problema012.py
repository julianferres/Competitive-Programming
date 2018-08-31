def triang(posicion):
	return posicion*(posicion+1)//2
	

def cant_div(triangular):
	contador=0
	if triangular==1:
		return 1
		
	for i in range(1,int(triangular**0.5) +1):
		if not triangular%i:
			contador+=1
	
	return 2*contador
	
def primer_triangular_con_divs(div):
	numero= 1
	while cant_div(triang(numero)) < div:
		numero+=1
	
	return triang(numero)
	
	
