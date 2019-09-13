import math
def ciclos(arr, i):
	d = {i:0}
	cnt = 1
	while True:
		i = arr[i]-1
		if i in d:
			return d[i],cnt-d[i]
		
		d[i] = cnt
		cnt+=1



def	mcm(a,b):
	return (a*b//math.gcd(a,b))
	
n = int(input())
a = [int(x) for x in input().split()]

max_offset = -float('inf')
act_mcm = 1
aux_max = -float('inf')

for i in range(n):
	off, lon = ciclos(a,i)
	aux = lon if (off==0) else lon*math.ceil(off/lon)
	max_offset = max(max_offset,off)
	aux_max = max(aux_max, aux)
	act_mcm = mcm(act_mcm,lon)
	

print(act_mcm*math.ceil(aux_max/act_mcm))