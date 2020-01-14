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

int main()
{
    FIN;
    multiset<ll> s;
    int n, q;
    cin >> n >> q;
    ll a[MAXN];
    forn(i, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    forn(i, q)
    {
        char type;
        cin >> type;
        if (type == '?')
        {
            ll k, x;
            cin >> k >> x;
        }
        else
        {
            ll a, b;
            cin >> a >> b;
        }
    }
    cout << s.upper_bound(2) - s.end() << endl;
    /*auto pos = s.upper_bound(3) - s.begin();
    auto pos = s.upper_bound(5) - s.begin();
    auto pos = s.upper_bound(6) - s.begin();*/

    return 0;
}
