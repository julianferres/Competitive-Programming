def A():
    mol, cant = input().split()
    aim = input()
    dic = {}
    for i in mol:
        if(i.isalpha()): dic[i] = 0
    for i in range(len(mol)):
        if(mol[i].isalpha()):
            if (i+1==len(mol) or mol[i+1].isalpha()):dic[mol[i]] += 1
            else:
                j = i+1
                while(j<len(mol) and mol[j].isdigit()): j+=1
                dic[mol[i]]+=int(mol[i+1:j])
    for i in dic:
        dic[i]*=int(cant)

    aim_dic = {}
    for i in aim:
        if(i.isalpha()): aim_dic[i] = 0
    for i in range(len(aim)):
        if(aim[i].isalpha()):
            if (i+1==len(aim) or aim[i+1].isalpha()):aim_dic[aim[i]] += 1
            else:
                j = i+1
                while(j<len(aim) and aim[j].isdigit()): j+=1
                aim_dic[aim[i]]+=int(aim[i+1:j])

    ans = float('inf')
    # print(aim_dic)
    # print(dic)
    for c in aim_dic:
        if c not in dic:
            print(0)
            return
        ans = min(ans, dic[c]//aim_dic[c])
    print(ans)

A()
