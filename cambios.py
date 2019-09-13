n = int(input())
s = input()

r_p = 0
r_i = 0
b_p = 0
b_i = 0


for i in range(n):

	if(i%2==0):
		if(s[i]=='b'):
			b_p+=1
		else:
			r_p+=1
	else:
		if(s[i]=='b'):
			b_i+=1
		else:
			r_i+=1

m1 = min(r_i,b_p)
sol1 = b_p-m1+r_i-m1 + m1

m2 = min(b_i,r_p)
sol2 = b_i-m2+r_p-m2+m2

print(min(sol1,sol2))
