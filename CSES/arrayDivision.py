def isPossible(n,a,suma,k):
	needed = 1; cum = 0; i = 0
	while(i<n):
		if(cum+a[i]>suma):
			cum = a[i]
			needed+=1
		else:
			cum+=a[i]
		i+=1
	return needed<=k

def main():
	n,k = map(int,input().split())
	a = [int(x) for x in input().split()]

	M = max(a); suma = sum(a)
	l,r = M, suma

	while(l<=r):
		if(l==r):
			print(l)
			return
		med = (l+r)//2
		if(isPossible(n,a,med,k) and not isPossible(n,a,med-1,k)):
			print(med)
			return
		if not isPossible(n,a,med,k): l = med+1
		else: r = med


main()