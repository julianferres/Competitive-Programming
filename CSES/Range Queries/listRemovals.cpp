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
    int n;
    cin >> n;
    ll a[MAXN];
    forn(i, n)
    {
        cin >> a[i];
        s.insert(mp(i, a[i]));
    }
    forn(i, n)
    {
        int pos;
        cin >> pos;
        pos--;
        ii x = *s.find_by_order(pos);
        cout << x.second << " ";
        s.erase(s.find_by_order(pos));
    }

    return 0;
}
