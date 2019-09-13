from logic import main
import collections

def bfs(graph, root):
    queue = collections.deque([root])
    global_vis.add(root)
    count = 1
    while queue:
        vertex = queue.popleft()
        for neighbour in graph[vertex]:
            if neighbour not in global_vis:
                global_vis.add(neighbour)
                count+=1
                queue.append(neighbour)
    return count
def main():
    global global_vis
    global_vis = set()
    L = []

    h , n , m = map(int,input().split())
    raw_graph = [input() for _ in range(n)]
    for i in range(n):
        if(not i%2):raw_graph[i]+=" "
    graph = {}

    for i in range(n):
        for j in range(2*m):
            if(raw_graph[i][j]=='.'): graph[(i,j)]=[]

    for i in range(n):
        for j in range(2*m):
            if(raw_graph[i][j]=='.'):
                if(j>2):
                    if(raw_graph[i][j-2]=='.'):
                        graph[(i,j)].append((i,j-2))
                        graph[(i,j-2)].append((i,j))
                if(j<2*m-2):
                    if(raw_graph[i][j+2]=='.'):
                        graph[(i,j)].append((i,j+2))
                        graph[(i,j+2)].append((i,j))
                if(i>0):
                    if(j>0):
                        if(raw_graph[i-1][j-1]=='.'):
                            graph[(i,j)].append((i-1,j-1))
                            graph[(i-1,j-1)].append((i,j))
                    if(j<2*m-1):
                        if(raw_graph[i-1][j+1]=='.'):
                            graph[(i,j)].append((i-1,j+1))
                            graph[(i-1,j+1)].append((i,j))
                if(i<n-1):
                    if(j>0):
                        if(raw_graph[i+1][j-1]=='.'):
                            graph[(i,j)].append((i+1,j-1))
                            graph[(i+1,j-1)].append((i,j))
                    if(j<2*m-1):
                        if(raw_graph[i+1][j+1]=='.'):
                            graph[(i,j)].append((i+1,j+1))
                            graph[(i+1,j+1)].append((i,j))

    for i in graph:
        if(i not in global_vis):
            L.append(bfs(graph, i))

    L.sort(reverse=True)
    ans = 0

    for comp in L:
        if(h==0): break
        ans+=1
        if(h > comp):
            h-=comp

        else:
            break
    print(ans)

main()
