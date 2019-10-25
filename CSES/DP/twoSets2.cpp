#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 501
#define MAXSUM 250001
int n,t;
int dp[MAXN][MAXSUM];

ll rec(int i, int s){
	if(i==n) return s==t;
	if(dp[i][s]!= -1) return dp[i][s];
	ll k = rec(i+1,s);
	if(s+i<=t) k+= rec(i+1,s+i);
	k%=MOD;
	return dp[i][s] = k;
}


int main(){ 
	FIN;
	cin >> n;
	t = n*(n+1)/2;
	if(n%4==1 || n%4==2) cout << "0" << endl;
	else{
		t/=2;
		forn(i,501) forn(j,250000) dp[i][j] = -1;
		ll ans = rec(1,0);
		if(ans<0) ans+=MOD;
		cout << ans << endl;
	}
	return 0;

}