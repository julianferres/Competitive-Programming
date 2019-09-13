from math import gcd, log

def parteLibreDe3(n):
    while(n%3==0):
        n = n//3
    return n


def orden(a,n):
    if(gcd(a,n) != 1):
        return n-1
    result = 1
    k = 1
    while(k<n):
        result = (result*a)%n
        if(result == 1):
            return k
        k+=1
    return n-1

def main():
    while(True):
        M = input()
        if(not M):
            break
        M = int(M)
        if(M==1):
            print(1)
        elif(M%2==0 or M%5==0):
            print(-1)
        elif(M%3!=0):
            print(orden(10,M))
        else:
            l = parteLibreDe3(M)
            if(l==1): ans = 1
            else: ans = orden(10,l)            
            i = 1     
            while(i*ans % (M//l) != 0):
                i+=1
            print(ans*i)
        

main()