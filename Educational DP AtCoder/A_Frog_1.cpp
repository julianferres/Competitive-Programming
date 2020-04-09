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
const ll INF = 1LL<<62;
#define MOD 1000000007
#define MAXN 200005

int main(){
    FIN;
    ll n;
    cin >> n;
    vi dp(n,INF), a(n);
    dp[0] = 0;
    forn(i, n) cin >> a[i];

    forn(i,n){
        if (i+1<n)
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
        if (i + 2 < n)
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
    }

    cout << dp[n - 1] << endl;
    
    return 0;
}

