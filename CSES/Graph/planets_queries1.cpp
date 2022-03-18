/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define MAXN 200005
#define MAXLOG 30 // log_2(MAXN)

int jump[MAXN][MAXLOG + 4]; // i --(2**j)-->jump[i][j]

int main()
{
    FIN;
    int n, q;
    cin >> n >> q;
    forn(i, n) cin >> jump[i + 1][0];

    forr(i, 1, MAXLOG + 1)
        forr(j, 1, n + 1)
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
    forn(i, q)
    {
        int x, k;
        cin >> x >> k;
        int idx = 0;
        while (k > 0)
        {
            if (k & 1)
                x = jump[x][idx];
            k >>= 1;
            idx++;
        }
        cout << x << endl;
    }

    return 0;
}
