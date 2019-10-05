def solve():
	n, x = map(int,input().split())
	a = [int(x) for x in input().split()]
	a = [(a[i],i) for i in range(n)]
	a.sort()
	pa ,pb = 0, n-1


	while(pa<pb):
		if(a[pa][0]+a[pb][0]==x): 
			a,b = min(a[pa][1]+1,a[pb][1]+1), max(a[pa][1]+1,a[pb][1]+1)
			print(a,b)
			return
		elif(a[pa][0]+a[pb][0]<x): pa+=1
		else:
			pb-=1
	print("IMPOSSIBLE")

solve()