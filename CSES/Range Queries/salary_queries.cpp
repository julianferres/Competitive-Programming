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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ii, null_type, less_equal<ii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    FIN;
    indexed_set s;
    int n, q;
    cin >> n >> q;
    ll a[MAXN];
    forn(i, n)
    {
        cin >> a[i];
        s.insert(mp(a[i], i));
    }
    forn(i, q)
    {
        char type;
        cin >> type;
        if (type == '!')
        {
            ll k, x;
            cin >> k >> x;
            k--;
            s.erase(s.find_by_order(s.order_of_key(mp(a[k], k))));
            s.insert(mp(x, k));
            a[k] = x;
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            cout << s.order_of_key(mp(b, n)) - s.order_of_key(mp(a - 1, n)) << endl;
        }
    }

    return 0;
}
