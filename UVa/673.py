def solve(s):
	st = []
	for c in s:
		if(len(st)==0):
			st.append(c)
		elif((st[-1]=='(' and c==')') or (st[-1]=='[' and c==']')):
			st.pop()
		else:
			st.append(c)




	print("No") if len(st) else print("Yes")





n = int(input())
for _ in range(n):
	solve(input())
