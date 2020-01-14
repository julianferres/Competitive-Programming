def fastio():
    import sys
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    def input(): return sys.stdin.readline().rstrip()
    sys.stdout = StringIO()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


fastio()

n, q = map(int, input().split())
a = [input() for _ in range(n)]
cum = [[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        cum[i][j] = cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]+(a[i-1][j-1] == '*')


def query(y1, x1, y2, x2):
    return cum[y2][x2]-cum[y1-1][x2]-cum[y2][x1-1]+cum[y1-1][x1-1]


for i in range(q):
    y1, x1, y2, x2 = map(int, input().split())
    print(query(y1, x1, y2, x2))
