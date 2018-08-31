def fibo(n):
	'''Da el n-esimo fibonacci.
	fibo(1)=1 y fibo(2)=2'''
	
	ant=1
	act=2
	
	if n==1:
		return (ant)
	elif n==2:
		return (act)
	
	for x in range (n-2):
		ant=ant+act
		act,ant = ant, act
	return (act)
	

def main():
	n=1
	suma=0
	while( fibo(n) < 4000000 ):
		
		if fibo(n)%2==0:
			suma+=fibo(n)
		
		n+=1

	print(suma)
 
main()
