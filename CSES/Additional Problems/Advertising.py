n = int(input())
A = [int(x) for x in input().split()]
if(len(A)==1):
    print(A[0])
s = []
maxarea = 0
i = 0
while(i<n):
    if(len(s)==0 or A[s[-1]]<=A[i]): s.append(i)
    else:
        while(len(s)>0 and A[s[-1]]>= A[i]):
            tp = s.pop()
            base = i if len(s)==0 else i-s[-1]-1
            h = A[tp]
            maxarea = max(base*h,maxarea)
        s.append(i)
    i+=1

while(len(s)>0):
    tp = s.pop()
    base = i if len(s)==0 else i-s[-1]-1
    h = A[tp]
    maxarea = max(base*h,maxarea)
print(maxarea)
        
