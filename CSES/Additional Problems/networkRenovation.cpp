/******************************************
*    AUTHOR:         julianferres         *
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
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005

vi g[MAXN], d(MAXN, 0);

int main()
{
    FIN;
    int n;
    cin >> n;
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b), g[b].pb(a);
        d[a]++, d[b]++;
    }
    vi leaves;
    forn(i, n) if (d[i] == 1) leaves.pb(i);
    cout << (leaves.size() + 1) / 2 << endl;
    if (leaves.size() & 1)
        cout << leaves[leaves.size() - 1] + 1 << " " << leaves[leaves.size() - 2] + 1 << endl;
    forn(i, leaves.size()) if (i & 1) cout << leaves[i - 1] + 1 << " " << leaves[i] + 1 << endl;

    return 0;
}
