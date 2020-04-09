/******************************************
*    AUTHOR:         julianferres         *
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
const int N = 405;
const ll inf = 1LL << 62;

int n; vi a(N);
vector<vi> dp(N, vi(N,-1));
vi pre(1,0);

ll fill(int l, int r){
	if (dp[l][r] != -1)
		return dp[l][r];

	if(l==r) return dp[l][r] = 0;
	if(l+1==r) return dp[l][r] = a[l] + a[r];
	ll actSum = pre[r + 1] - pre[l];
	ll ans = inf;
	forr(i,l,r){
		ll ansl = fill(l,i);
		ll ansr = fill(i+1,r);
		
		ans = min(ans, ansl+ansr+actSum);
	}
	return dp[l][r] = ans;

}

// 10 20 30 40

int main()
{
	FIN;
	cin >> n;
	forn(i,n) cin >> a[i];
	forn(i, n) pre.pb(pre[i] + a[i]);

	// DBGV(pre, n+1);
	cout << fill(0, n - 1) << endl;
	// forn(j, n) DBGV(dp[j], n);

	return 0;
}
