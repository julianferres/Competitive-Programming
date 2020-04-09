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

int D; string k;

void add( ll &a, ll b){
	a+=b;
	while(a>=mod) a-=mod;
	while(a<0) a+=mod;
}

int main(){
    FIN;
    cin >> k >> D;
    ll len = k.size();
	vector<vi> dp(105, vi(2, 0));
	dp[0][0] = 1;
	forn(where, len)
	{
		vector<vi> new_dp(105, vi(2,0));
    	forn(sum, D){
    		for(auto sm_already: {false, true}){
    			forn(digit, 10){
    				if(k[where]-'0'<digit && !sm_already) break;
    				add(new_dp[(sum+digit)%D][sm_already || (digit<k[where]-'0')],
					dp[sum][sm_already]);
    			}
    		}
    	}
    	dp = new_dp;
	}
	ll ans = (dp[0][false] + dp[0][true]) % mod;
	add(ans, -1);
	cout << ans << endl;

	return 0;
}

