def es_primo(n):
	
	for x in range(2, int(n//2)+1):
		if n%x==0:
			return False
	
	return True
	
def max_p(num):
	prim_max=1
	
	if es_primo(num):
		return num
		
	for x in range (2,num//2+1):
		if es_primo(x) and num%x==0:
			return max_p(num//x)
			
	

