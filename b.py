s = input()
l = len(s)

c1, c2, c3, c4, c5 = 0, 0, 0, 0, 0

for i in range(l-5+1):
	if(s[i:i+5]=="Danil"):
		c1+=1
for i in range(l-4+1):
	if(s[i:i+4]=="Olya"):
		c2+=1
for i in range(l-5+1):
	if(s[i:i+5]=="Slava"):
		c3+=1
for i in range(l-3+1):
	if(s[i:i+3]=="Ann"):
		c4+=1
for i in range(l-6+1):
	if(s[i:i+6]=="Nikita"):
		c5+=1

if(c1+c2+c3+c4+c5 == 1):
	print("YES")

else:
	print("NO")