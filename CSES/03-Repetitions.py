# Repetitions
# https://cses.fi/problemset/task/1069
s = input()
m = float('-inf')

aux = 1
for i in range(1,len(s)):
    if(s[i]==s[i-1]):
        aux+=1
    else:
        m = max(aux,m)
        aux = 1
m = max(aux,m)
print(m)
