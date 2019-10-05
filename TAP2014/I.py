def is_prime(n):
    """Naive O(sqrt(n)) approach"""
    d = 2
    while(d*d<=n):
        if(n%d == 0):
            return False
        d+=1
    return True

for i in range(2184,2200):
	if(is_prime(i)):
		print(i)
