/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MAXN 100005
#define INF 1e18

//DSU
int parent[MAXN], size[MAXN];
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    FIN;
    int n, m;
    cin >> n >> m;
    forn(i, n) make_set(i);
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        union_sets(a, b);
    }
    vi coins;
    vector<bool> seen(n, false), ans(n + 1, false);
    ans[0] = true;
    forn(i, n)
    {
        int par = find_set(i);
        if (seen[par])
            continue;
        else
            seen[par] = true, coins.pb(size[par]);
    }
    map<int, int> cnt;
    for (auto x : coins)
        cnt[x]++;

    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        int size = it->first, times = it->second;
        vi last(size, -1);
        vector<bool> nuevo(n + 1, false);
        forn(i, n + 1)
        {
            if (last[i % size] != -1 && last[i % size] >= i - times * size)
            {
                nuevo[i] = true;
            }

            if (ans[i])
                last[i % size] = i;
        }
        forn(i, n + 1) ans[i] = ans[i] | nuevo[i];
    }

    forr(i, 1, n + 1) cout << ans[i];
    cout << endl;
    return 0;
}
