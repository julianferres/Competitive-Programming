/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
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
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

int n, m;
vi g[MAXN];
vi paths[MAXN];
vector<bool> seen(MAXN, false);
vector<ll> ans(MAXN, 0);

set<ll> dfs(ll u)
{
    set<ll> t;
    //Almacena los path de los hijos ya vistos no resueltos
    seen[u] = true;
    for (auto v : g[u])
    {
        if (seen[v])
            continue;
        set<ll> x = dfs(v);
        ans[u] += x.size(); //Paths que no se resolvieron en subtree(x)
        if (x.size() > t.size())
            swap(x, t);

        for (auto y : x)
        {
            if (esta(y, t))
                t.erase(y); //Se resuelve en subtree(u)
            else
                t.insert(y); //Todavia no resuelto
        }
    }
    //Los path que quedan deben venir de algun padre de u
    ans[u] = (ans[u] - t.size()) / 2; //Los resueltos los conte 2 veces
    ans[u] += t.size();               //Los de padres

    for (auto path_u : paths[u])
    {
        if (esta(path_u, t))
            t.erase(path_u);
        else
        { //Los que arrancan en u y suben a padres
            ans[u]++;
            t.insert(path_u);
        }
    }
    return t;
}

int main()
{
    FIN;
    cin >> n >> m;
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        paths[a].pb(i);
        paths[b].pb(i);
    }
    dfs(0);
    forn(i, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
