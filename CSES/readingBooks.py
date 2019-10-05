n = int(input())
a = sorted([int(x) for x in input().split()])
print(a[-1]+max(a[-1],sum(a[:-1])))