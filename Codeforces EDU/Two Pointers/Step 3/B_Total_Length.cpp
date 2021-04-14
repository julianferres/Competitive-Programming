/*    AUTHOR: julianferres    */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+10; // const ll INF = 1e18+10;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

ll tri(ll n){ return n*(n+1)/2; }

int main(){  
    FIN;

    int n; cin >> n;
    ll s; cin >> s;

    vi a(n); forn(i, n) cin >> a[i];

    ll ans = 0, act_sum = 0;

    int l = 0, r = 0;

    while(r < n){
        act_sum += a[r];

        while(l < r && act_sum > s){
            act_sum -= a[l];
            l++;
        }
        if(act_sum <= s)
            ans += tri(r - l + 1);
        r++;
    }


    cout << ans << "\n";

    return 0;
}