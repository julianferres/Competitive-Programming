h , w  = map(int, input().split())

grid = [input() for _ in range(h)]

sum , cnt = 0,0

for i in range(h):
    for j in range(w):
        if(grid[i][j]!='.'):
            sum+=(j+0.5)
            cnt+=1

bar_x = sum/cnt

base_left , base_right = float('inf') , 0
for i in range(len(grid[-1])):
    if(grid[-1][i] !='.'):
        base_left = min(base_left , i)
        base_right = max(base_right, i)

if(bar_x<base_left): print("left")
elif(base_left<= bar_x <= base_right+1): print("balanced")
else: print("right")
