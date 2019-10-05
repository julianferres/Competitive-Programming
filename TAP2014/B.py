def solve(n):
	ans = []
	while(n>0):
		if(n%3==0):
			ans.append("0")
		elif(n%3==1):
			ans.append("+")
			n-=1
		else:
			ans.append("-")
			n+=1
		n//=3
	print("".join(ans[::-1]))



t = int(input())
for _ in range(t):
	x = int(input())
	solve(x)
