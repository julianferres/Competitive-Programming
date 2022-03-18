# Two Knights
# https://cses.fi/problemset/task/1072
d = [0]
f = lambda k : 2*k**3+3*k**2-7*k+8
# Esta f es tal que a_k+1 = a_k + f(k)
# y viene de f(k) = 5(k^2-2)+4(k^2-3)+(2k-8)(k^2-4)+(2k+1)k-2
for i in range(1,10005):
    d.append(d[-1]+f(i))
n = int(input())
for i in range(n):
    print(d[i])
