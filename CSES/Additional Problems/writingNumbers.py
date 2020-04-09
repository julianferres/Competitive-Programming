def countDigitOne(n):
    ones, m = 0, 1
    while m <= n:
        ones += (n//m + 8) // 10 * m + (n//m % 10 == 1) * (n%m + 1)
        m *= 10
    return ones
 
def bs(x):
    l, r = 0, 10 ** 36
    ans = r
    while (l <= r):
        mid = l + (r - l) // 2
        if (countDigitOne(mid) > x):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    return ans
 
print(bs(int(input()))-1)