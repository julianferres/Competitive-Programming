#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define inf 2500000
#define MAXA 500
#define MAXB 500
int dp[MAXA+1][MAXB+1];

int rec(int c, int d){
	int a,b;
	a = min(c,d); b = max(c,d);
	if(dp[a][b]!=-1) return dp[a][b];
	if(a<1) return dp[a][b]=inf;
	if(a==1) return dp[a][b]=b-1;
	int m = inf;
	fore(i,1,b/2+1) m = min(m,1+rec(i,a)+rec(b-i,a));
	fore(j,1,a/2+1) m = min(m,1+rec(a-j,b)+rec(j,b));
	return dp[a][b]=m;
}


int main(){ 
	FIN;
	int a,b; cin >> a >> b;
	int c,d;
	c = min(a,b); d = max(a,b);
	forn(i,MAXA+1)forn(j,MAXB+1) dp[i][j]=-1;
	fore(i,1,MAXA+1) dp[i][i]=0;
	int ans = rec(c,d);
	cout << ans << endl;
	return 0;
}