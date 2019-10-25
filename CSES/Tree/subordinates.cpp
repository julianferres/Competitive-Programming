#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define MAXN 2000007
vector<int> g[MAXN];
int dp[MAXN];

int fill(int i){
	if(!g[i].sz) return dp[i]=0;
	if(dp[i]!=-1) return dp[i];
	int aux = 0;
	for(auto ch: g[i]) aux+=(1+fill(ch));
	return dp[i]=aux;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	forn(i,n-1){
		int a; cin >> a; a--;
		g[a].pb(i+1);
	}
	memset(dp,-1,sizeof(dp));
	fill(0);
	forn(i,n) cout << dp[i] << " ";
	cout << endl;
	return 0;
}
