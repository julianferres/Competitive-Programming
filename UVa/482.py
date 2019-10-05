T = int(input())
input()

for aa in range(T):
	orden = [int(x) for x in input().split()]
	a = input().split()
	out = [None for i in range(len(orden))]
	for i in range(len(orden)):
		out[orden[i]-1] = a[i]
	for i in out: print(i)
	if(aa!=T-1):
		input()
		print("")


