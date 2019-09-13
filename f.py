def cantidadz(n):
	cum = 0
	for pot in range(1,14):
		cum+= n//(5**pot)

	return cum



t = int(input())

for _ in range(t):
	n = int(input())
	print(cantidadz(n))