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

int main()
{
    FIN;
    ll n, k;
    cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];
    ll suma = 0;
    forn(i, n) suma += a[i];
    if (suma <= k)
    {
        cout << 1 << endl;
        return 0;
    }
    forn(i, n) a.pb(a[i]);
    forn(i, n) a.pb(a[i]);
    int c_act = 1;
    vi lens;
    ll s_act = a[0];
    forr(i, 1, 3 * n)
    {
        if (s_act + a[i] <= k)
        {
            c_act++;
            s_act += a[i];
        }
        else
        {
            lens.pb(c_act);
            s_act = a[i];
            c_act = 1;
        }
    }
    lens.pb(c_act);
    vi cum(1, lens[0]);
    forr(i, 1, lens.size()) cum.pb(cum.back() + lens[i]);
    ll ans = n;
    forn(i, cum.size())
    {
        ll idx = lower_bound(all(cum), cum[i] + n) - cum.begin();
        if (idx < cum.size())
            ans = min(ans, idx - i);
    }
    cout << ans << endl;

    return 0;
}
