def sig_collatz(n):
	
	if n%2:
		return 3*n+1
	
	return n//2


def long_collatz(num):
	
	contador=1
	while(num > 1):
		num = sig_collatz(num)
		contador+=1
	
	return contador
	
def find_max_collatz( techo ):
	max = 1,1 
	
	for i in range (2,techo+1):
		num,collatz_ant = max
		act=long_collatz(i)
		if act > collatz_ant:
			print( i, act )
			max = i , act
			
			
	return max
	
