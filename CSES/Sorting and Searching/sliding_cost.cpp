/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define MAXN 200005

int main()
{
    FIN;
    ll n, k;
    cin >> n >> k;
    ll a[MAXN];
    forn(i, n) cin >> a[i];
    indexed_set s;
    forn(i, k) s.insert(a[i]);

    ll old_m = *s.find_by_order((k + 1) / 2 - 1);
    ll d = 0;
    forn(i, k) d += abs(a[i] - old_m);

    cout << d;
    forn(i, n - k)
    {
        s.erase(s.find_by_order(s.order_of_key(a[i])));
        s.insert(a[i + k]);
        ll m = *s.find_by_order((k + 1) / 2 - 1);
        d = d + abs(m - a[i + k]) - abs(old_m - a[i]);
        if (k % 2 == 0)
            d -= (m - old_m);
        old_m = m;
        cout << " " << d;
    }
    cout << endl;

    return 0;
}
