t = int(input())
for _ in range(t):
	n=int(input()); a=[int(x) for x in input().split()]
	ans = 0; 
	for i in range(1,n,2): ans^=a[i]
	print("first") if ans else print("second")
