class SegmentTreeGeneric:
    def __init__(self, array, f):
        self.n = len(array)
        self.t = [0]*self.n + array
        self.f = f

        for i in range(self.n-1, 0, -1):
            self.t[i] = self.f(self.t[i<<1],self.t[(i<<1)|1])

    def query(self, l, r):
        res = 0 #Se usa el neutro de la operacion
        l+=self.n ; r+=self.n
        
        while(l<r):
            if(l&1):
                res = self.t[l] if res==0 else self.f(res,self.t[l])
                l+=1
            if(r&1):
                r-=1
                res = self.t[r] if res==0 else self.f(self.t[r],res)
            l>>=1; r>>=1

        return res

n, q = map(int,input().split())
a = [int(x) for x in input().split()]
stree = SegmentTreeGeneric(a,min)

for _ in range(q):
    a,b = map(int,input().split())
    print(stree.query(a-1,b))