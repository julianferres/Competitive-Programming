# Missing Number
# https://cses.fi/problemset/task/1083
n = int(input())
a = [int(x) for x in input().split()]
print(n*(n+1)//2-sum(a))
