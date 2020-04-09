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
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int inf = 1<<30; // const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 3005;

ll dp[N][N],pre[N][N]; //dp[i][j] using i numbers and finish with j
int n; string s;

void add(ll &a, ll b){
	a+=b;
	if(a>=mod) a-=mod;
}

int main(){
    FIN;
    cin >> n >> s;
    dp[1][1] = 1;

    forr(i,2,n+1){
    	forr(a,1,i) pre[i-1][a] = pre[i-1][a-1] + dp[i-1][a];
    	forr(a,1,i+1){
    		ll l,r;
    		if(s[i-2] == '<') l = 1, r = a-1;
    		else l = a, r = i-1;
            if(l<=r) dp[i][a] = (pre[i-1][r]-pre[i-1][l-1]+mod)%mod;
    	}

    }

    ll ans = 0;
    forr(i,1,n+1) add(ans, dp[n][i]);
    cout << ans << endl;
    
    return 0;
}

