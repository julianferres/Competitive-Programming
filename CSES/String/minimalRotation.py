def least_rotation(S):
    S+=S
    f = [-1]*len(S)
    k = 0
    for j in range(1,len(S)):
        sj = S[j]
        i  = f[j-k-1]
        while i!=-1 and sj!=S[k+i+1]:
            if sj<S[k+i+1]: k = j-i-1
            i = f[i]
        if sj!=S[k+i+1]:
            if sj<S[k]: k = j
            f[j-k] = -1
        else:
            f[j-k] = i+1
    return k

s = input()
k = least_rotation(s)
print(s[k:]+s[:k])