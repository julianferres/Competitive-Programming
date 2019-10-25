n = input()
 
d = {x:False for x in ['A','C','G','T']}
ans = ""
last_added = False
for i in n:
	d[i] = True
	if(list(d.values())==[True]*4):
		ans += i
		for j in d: d[j]=False
		last_added = True
for i in d:
	if not d[i]:
		ans+=i
		break
print(ans)
