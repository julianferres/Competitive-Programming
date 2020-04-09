/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " \n"[i==n-1];
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int K = 100005;
const int N = 105;
const int mod = 1000000007;

void add(ll &a, ll b){
	a+=b;
	if(a>=mod) a-=mod;
}
void sub(ll &a, ll b){
	a-=b;
	if(a<0) a+=mod;
}

int n,k;
vi a(N);
vector<vi> dp(N,vi(K,0)); 
vector<vi> pre(N,vi(K,0)); // dp[i][j] = dp[i][0] + ... + dp[i][j]

int main()
{
	FIN;
	cin >> n >> k;
	forn(i,n) cin >> a[i];

	forn(value,a[0]+1) add(dp[0][value],1);

	add(pre[0][0],1);
	sub(pre[0][a[0]+1],1);

	forr(i,1,n){
		forn(j,k+1){
			ll tmp = dp[i - 1][j];
			add(pre[i][j], tmp);
			if(j+a[i]<=k)
				sub(pre[i][j + a[i] + 1], tmp);
			// dp[i][j] = dp[i][j-a[i]] + ... + dp[i][j]
		}
		ll prefix = 0;
		forn(j,k+1){
			add(prefix, pre[i][j]);
			add(dp[i][j], prefix);
		}
	}
	cout << dp[n-1][k] << endl;

	return 0;
}


