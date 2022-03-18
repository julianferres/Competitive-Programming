MAX = 1000001


class Query:
    def __init__(self, l, r, idx):
        self.l = l
        self.r = r
        self.idx = idx

# updating the bit array


def update(idx, val, bit, n):
    while idx <= n:
        bit[idx] += val
        idx += idx & -idx

# querying the bit array


def query(idx, bit, n):
    summ = 0
    while idx:
        summ += bit[idx]
        idx -= idx & -idx
    return summ


def answeringQueries(arr, n, queries, q):

    # initialising bit array
    bit = [0] * (n + 1)

    # holds the rightmost index of
    # any number as numbers of a[i]
    # are less than or equal to 10^6
    last_visit = [-1] * MAX

    # answer for each query
    ans = [0] * q

    query_counter = 0
    for i in range(n):

        # If last visit is not -1 update -1 at the
        # idx equal to last_visit[arr[i]]
        if last_visit[arr[i]] != -1:
            update(last_visit[arr[i]] + 1, -1, bit, n)

        # Setting last_visit[arr[i]] as i and
        # updating the bit array accordingly
        last_visit[arr[i]] = i
        update(i + 1, 1, bit, n)

        # If i is equal to r of any query store answer
        # for that query in ans[]
        while query_counter < q and queries[query_counter].r == i:
            ans[queries[query_counter].idx] = \
                query(queries[query_counter].r + 1, bit, n) - \
                query(queries[query_counter].l, bit, n)
            query_counter += 1

    # print answer for each query
    for i in range(q):
        print(ans[i])


n, q = map(int, input().split())
a = [int(x) for x in input().split()]
queries = []
for i in range(q):
    l, r = map(int, input().split())
    queries.append(Query(l-1, r-1, i))
queries.sort(key=lambda x: x.r)
answeringQueries(a, n, queries, q)
