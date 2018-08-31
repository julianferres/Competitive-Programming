def es_palindromo(num):
	aux=0
	while num> aux:
		last= num%10
		num = num//10
		aux=aux*10+last
	if aux== num:
		return True
	return False
