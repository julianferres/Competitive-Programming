f = lambda m,n : (m**2-m+n**2+n)/2
def J():
    m = int(input())
    for n in range(m+2,10**7+1):
        if(int((f(m,n)**0.5))**2==f(m,n)):
            print(m,int(f(m,n)**0.5),n)
            return

J()
