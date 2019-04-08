# Missing Number
# https://cses.fi/problemset/task/1083
n = int(input())
a = [int(x) for x in input().split()]

s = n*(n+1)//2
print(s-sum(a))
