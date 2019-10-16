def solve():
	t = int(input())
	for _ in range(t):
		a,b = map(int,raw_input().split())
		if(2*b>=a and 2*a>=b and (2*b-a)%3==0 and (2*a-b)%3==0):
			print("YES")
		else:
			print("NO")


if __name__=="__main__":
	solve()