/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define FIN ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define MOD 1000000007
#define MAXN 21

vi g[MAXN];
ll dp[1 << MAXN][MAXN];
ll dfs(int state, int v)
{
    ll aux = 0;
    for (auto u : g[v])
    {
        if (state & (1 << u))
        {
            if (dp[state - (1 << v)][u] > -1)
                aux += dp[state - (1 << v)][u];
            else
                aux += dfs(state - (1 << v), u);
        }
    }
    return dp[state][v] = aux % MOD;
}

int main()
{
    FIN;
    int n, m, a, b;
    cin >> n >> m;
    forn(i, m)
    {
        cin >> a >> b;
        a--, b--;
        g[b].pb(a); //DFS al reves
    }
    forn(i, 1 << MAXN) forn(j, MAXN)
        dp[i][j] = (!(i & 1) || !i || !((1 << j) & i)) ? 0 : -1;
    dp[1][0] = 1;

    dfs((1 << n) - 1, n - 1);
    cout << dp[(1 << n) - 1][n - 1] % MOD << endl;
    return 0;
}
