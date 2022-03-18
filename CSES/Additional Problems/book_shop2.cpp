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
#define MOD 1000000007
#define MAXN 100
#define INF 1e18

ll h[MAXN], s[MAXN], k[MAXN];
vi new_h, new_s;

ll pot2(ll x)
{
    ll ans = 1;
    while (2 * ans <= x)
        ans <<= 1;
    return ans >> 1;
}

ll knapsack(int x, vi wt, vi val, int n)
{
    ll prev[x + 1];
    ll act[x + 1];
    forn(i, n + 1)
    {
        forn(w, x + 1)
        {
            if (i == 0 || w == 0)
                act[w] = 0;
            else if (wt[i - 1] <= w)
                act[w] = max(val[i - 1] + prev[w - wt[i - 1]], prev[w]);
            else
                act[w] = prev[w];
        }
        forn(i, x + 1) prev[i] = act[i];
    }
    return prev[x];
}

int main()
{
    FIN;
    int n, x;
    cin >> n >> x;
    forn(i, n) cin >> h[i];
    forn(i, n) cin >> s[i];
    forn(i, n) cin >> k[i];

    //Descompongo los k en pots de 2 asi tengo a lo sumo n*logn
    //Que va bien con knapsack
    forn(i, n)
    {
        ll max_pot_2 = pot2(k[i]);
        if (max_pot_2 < k[i])
        {
            new_h.pb(h[i] * (k[i] - (max_pot_2 << 1) + 1));
            new_s.pb(s[i] * (k[i] - (max_pot_2 << 1) + 1));
        }
        while (max_pot_2)
        {
            new_h.pb(h[i] * (max_pot_2));
            new_s.pb(s[i] * (max_pot_2));
            max_pot_2 >>= 1;
        }
    }
    cout << knapsack(x, new_h, new_s, new_h.size()) << endl;

    return 0;
}
