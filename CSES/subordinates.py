import sys; sys.setrecursionlimit(10**8)
class TreeNode():
	def __init__(self):
		self.child = []


n = int(input())
parents = [None,None]+[int(x) for x in input().split()]

nodes = [TreeNode() for i in range(n+1)]

for i in range(2,n+1):
	nodes[parents[i]].child.append(i)

sub = [-1 for i in range(n+1)]
def rec(i):
	if(sub[i]!=-1):
		return sub[i]
	if(len(nodes[i].child)==0):
		sub[i]=0
		return sub[i]
	else:
		ans = 0
		for ch in nodes[i].child:
			ans+= rec(ch)+1
		sub[i] = ans
		return sub[i]
rec(1)
print(*sub[1:])




