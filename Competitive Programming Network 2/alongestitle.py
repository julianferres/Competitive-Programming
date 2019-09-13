def findPosition(k, M):
	f0,f1 = 0 , 1
	i = 2
	while(True):
		f2 = f0 + f1
		if(f2%M == 0):
			return k*i
		f0 = f1
		f1 = f2
		i+=1

while(True):
	i = input()
	if(not i):
		break
	k, M = map(int,i.split())
	if(M==1): print(k)
	else: print(findPosition(k,M))