from collections import Counter

def bomb():
	n, m = map(int, input().split())

	a = []
	cols = [0]*m
	rows = [0]*n

	mas2_r = n- Counter(rows)[0] - Counter(rows)[1]
	mas2_c = m- Counter(cols)[0] - Counter(cols)[0]

	if(mas2_r>= 2 or mas2_c>=2):
		print("NO")
		return

	for i in range(n):
		s = input()
		a.append(s)
		rows[i] = Counter(s)['*']

	for i in range(n):
		for j in range(m):
			if(a[i][j]=='*'):
				cols[j]+=1
	i_x , i_y = None, None
	for i in range(n):
		for j in range(m):
			if(a[i][j]=='*'):
				for r in range(n):
					if(r==i):
						continue
					if(rows[r]>=2):
						i_x = r
					if(rows[r]==1 and a[r][j]!='*'):
						print("NO")
						return

				for c in range(m):
					if(c==j):
						continue
					if(cols[c]>=2):
						i_y = c
					if(cols[c]==1 and a[i][c]!='*'):
						print("NO")
						return

				ans_x = i_x if (i_x is not None) else i
				ans_y = i_y if (i_y is not None) else j

				print("YES")
				print(ans_y+1,ans_x+1)

				return

	print("YES")
	print(1,1)

bomb()