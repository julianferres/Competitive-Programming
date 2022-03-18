def prevSmaller(A):
        ans = []
        stack = [-1]
        stackidx = [0]
    
        for i in range(len(A)):
            if(stack[-1]< A[i]):
                ans.append(stackidx[-1])
                stack.append(A[i])
                stackidx.append(i+1)
            else:
                while(stack[-1]>= A[i]):
                    stack.pop()
                    stackidx.pop()
                ans.append(stackidx[-1])
                stack.append(A[i])
                stackidx.append(i+1)
        return ans
n = input(); A = [int(x) for x in input().split()]
print(*prevSmaller(A))

