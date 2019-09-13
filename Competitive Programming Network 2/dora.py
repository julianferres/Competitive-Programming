tri = lambda x: x*(x+1)//2

def getPosition(x,y):
	diag = x+y-1

	if(diag%2):
		output = tri(diag)-abs(x-1)
	else:
		output = tri(diag)-abs(y-1)

	return output

while(True):
	x, y = map(int, input().split())
	if(x==0 and y == 0):
		break
	print(getPosition(x,y))