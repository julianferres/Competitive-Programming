n = int(input())
p = [int(x) for x in input().split()]

#Manzanas, indice, suma_elegidos, suma_no_elegidos
def rec(p, i, a,b):
	if(i == len(p)):
		return abs(a-b)
	else:
		return min(rec(p,i+1,a+p[i],b),rec(p,i+1,a,b+p[i]))

print(rec(p,0,0,0))