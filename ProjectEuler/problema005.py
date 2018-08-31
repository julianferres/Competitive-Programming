def busca_mcm():
	
	mul=19
	
	while(mul%16 or mul%9 or mul%5 or mul%7 or mul%11 or mul%13 or mul%17):
		mul+=19
	
	return mul


busca_mcm()
