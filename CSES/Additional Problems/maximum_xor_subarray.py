def max_xor(arr, n):
    maxx = 0
    mask = 0
    se = set()
    for i in range(30, -1, -1):
        mask |= (1 << i)
        newMaxx = maxx | (1 << i)

        for i in range(n):
            se.add(arr[i] & mask)
        for prefix in se:
            if newMaxx ^ prefix in se:
                maxx = newMaxx
                break

        se.clear()
    return maxx


n = int(input())
cum = [0]
a = [int(x) for x in input().split()]
for i in range(n):
    cum.append(cum[-1] ^ a[i])
print(max_xor(cum, n+1))
