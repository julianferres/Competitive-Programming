def convex_hull(points):
    points = sorted(set(points))

    if len(points) <= 1:
        return points

    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)

    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]


def d():
    total = []

    n = int(input())
    a, b = [], []
    for i in range(n):
        x,y = map(int,input().split())
        total.append((x,y))
        a.append((x,y))

    m = int(input())

    for j in range(m):
        x,y = map(int,input().split())
        total.append((x,y))
        b.append((x,y))
  
    set_a = set()
    for i in a:
        set_a.add(i)
    for j in b:
        if(j in set_a):
            print("NO")
            return


    if(sorted(a)==sorted(convex_hull(total))):
        print("YES")
    else:
        print("NO")

d()