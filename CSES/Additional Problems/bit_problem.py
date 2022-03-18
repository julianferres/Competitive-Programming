M = 21
n = int(input())
a = [int(x) for x in input().split()]
b, c = [0]*(1 << M), [0]*(1 << M)
for i in a:
    b[i] += 1
    c[i] += 1

for i in range(M):
    for x in range(1 << M):
        if x & (1 << i):
            b[x] += b[x ^ (1 << i)]
        else:
            c[x] += c[x ^ (1 << i)]

for x in a:
    print(b[x], c[x], n-b[(1 << M)-1-x])
