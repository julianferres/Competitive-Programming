# Python3 implementation of the approach 
V_SUM_MAX = 100*10**3+5
N_MAX = 100+5
W_MAX = 10**9+5
  
# To store the states of DP 
dp = [[ 0 for i in range(N_MAX)] 
          for i in range(V_SUM_MAX + 1)] 
v = [[ 0 for i in range(N_MAX)] 
         for i in range(V_SUM_MAX + 1)] 
  
# Function to solve the recurrence relation 
def solveDp(r, i, w, val, n): 
      
    # Base cases 
    if (r <= 0): 
        return 0
    if (i == n): 
        return W_MAX 
    if (v[r][i]): 
        return dp[r][i] 
  
    # Marking state as solved 
    v[r][i] = 1
  
    # Recurrence relation 
    dp[r][i] = min(solveDp(r, i + 1, w, val, n),  
            w[i] + solveDp(r - val[i], i + 1, 
                            w, val, n)) 
    return dp[r][i] 
  
# Function to return the maximum weight 
def maxWeight( w, val, n, c): 
  
    # Iterating through all possible values 
    # to find the the largest value that can 
    # be represented by the given weights 
    for i in range(V_SUM_MAX, -1, -1): 
        if (solveDp(i, 0, w, val, n) <= c): 
            return i 
  
    return 0
  
n,C = map(int, input().split())
w = [] 
val = [] 
for i in range(n):
    wei,vv = map(int, input().split())
    w.append(wei)
    val.append(vv)    

print(maxWeight(w, val, n, C)) 

