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
#define MAXN 100005
#define INF 1e18

ll max_xor(ll arr[], ll n)
{
    ll mask = 0, maxx = 0;
    unordered_set<ll> se;
    for (ll i = 30; i >= 0; --i)
    {
        mask |= (1 << i);
        ll newMaxx = maxx | (1 << i);

        forn(i, n)
            se.insert(arr[i] & mask);
        for (ll prefix : se)
        {
            if (esta(newMaxx ^ prefix, se))
            {
                maxx = newMaxx;
                break;
            }
        }
        se.clear();
    }
    return maxx;
}

int main()
{
    FIN;
    ll n;
    cin >> n;
    ll a[n + 5];
    forn(i, n) cin >> a[i];
    ll cum[n + 5];
    cum[0] = 0;
    forn(i, n)
        cum[i + 1] = cum[i] ^ a[i];

    cout << max_xor(cum, n + 1) << endl;
    return 0;
}
