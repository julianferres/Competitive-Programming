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
#define MAXN 1005
#define INF 1e18

ll cum[MAXN + 5][MAXN + 5];

int main()
{
    FIN;
    int n, q;
    cin >> n >> q;
    bool a[n + 5][n + 5];
    forn(i, n)
    {
        forn(j, n)
        {
            char vij;
            cin >> vij;
            a[i][j] = (vij == '*');
        }
    }

    forr(i, 1, n + 1)
        forr(j, 1, n + 1)
            cum[i][j] = cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1] + a[i - 1][j - 1];

    forn(i, q)
    {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << cum[y2][x2] - cum[y1 - 1][x2] - cum[y2][x1 - 1] + cum[y1 - 1][x1 - 1]
             << endl;
    }
    return 0;
}
