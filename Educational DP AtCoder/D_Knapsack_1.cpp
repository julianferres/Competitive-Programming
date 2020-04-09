/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005



ll knapsack(ll x, vi wt, vi val, ll n)
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
        forn(l, x + 1) prev[l] = act[l];
    }
    return prev[x];
}

int main(){
    FIN;
    ll n, w;
    cin >> n >> w;
    vi val(n), wt(n);
    forn(i, n) cin >> wt[i] >> val[i];

    ll ans = knapsack(w, wt, val, n);
    cout << ans << endl;

    return 0;
}
