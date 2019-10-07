s = {}
cum = {}

s[1] = 2/3
cum[1] = s[1]

for i in range(2,10**9+3):
	s[i] = ((i+1)/(i+2)-cum[i-1])/i
	cum[i] = cum[i-1]+s[i]


T = int(input())

for i in range(T):
	n = int(input())
	print("{0:.11f}".format(s[n]))



