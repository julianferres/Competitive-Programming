/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef set<ii> sii;
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
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

int n, m, k, ans, parent[MAXN], size[MAXN];
void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        ans--;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    FIN;
    int n, m, k;
    cin >> n >> m >> k;
    ans = n;
    forn(i, n) make_set(i);
    sii edges;
    forn(i, m)
    {
        int u, v;
        cin >> u >> v;
        int a = min(u, v), b = max(u, v);
        edges.insert(mp(a, b));
    }
    vii removals;
    forn(i, k)
    {
        int u, v;
        cin >> u >> v;
        int a = min(u, v), b = max(u, v);
        removals.pb(mp(a, b));
        edges.erase(mp(a, b));
    }
    /*RAYA;
    for (auto e : edges)
        cout << e.first << " " << e.second << endl;
    RAYA;
    for (auto e : removals)
        cout << e.first << " " << e.second << endl;*/
    reverse(all(removals));
    removals.pop_back(); //El ultimo no importa

    for (auto x : edges)
        union_sets(x.first, x.second);
    vi vans = {ans};
    for (auto x : removals)
    {
        union_sets(x.first, x.second);
        vans.pb(ans);
    }
    reverse(all(vans));
    forn(i, vans.size()) cout << vans[i] << " \n"[i == vans.size() - 1];

    return 0;
}
