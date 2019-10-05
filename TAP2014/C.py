from collections import defaultdict
med = lambda x,y : (float(x[0]+y[0])/2,float(x[1]+y[1])/2)
ans = 0
n = int(raw_input())
p = []
for _ in range(n):
	a,b = raw_input().split()
	p.append((int(a),int(b)))
medios = defaultdict(list)
ans = 0
for i in range(n):
	for j in range(i+1,n):
		medios[med(p[i],p[j])].append((p[i],p[j]))

for med in medios:
	pendientes = defaultdict(int)
	if(len(med)==1):
		continue
	for seg in medios[med]:
		p1 = seg[0]
		p2 = seg[1]
		if(p2[0]-p1[0] == 0):
			pendientes["cero"]+=1
		else:
			pendientes[float(p2[1]-p1[1])/(p2[0]-p1[0])]+=1
	suma = 0
	for p in pendientes:
		suma+=pendientes[p]
	suma = suma**2
	for p in pendientes:
		suma-= (pendientes[p])**2
	suma/=2
	ans+=suma



print(ans)