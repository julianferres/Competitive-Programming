#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define MAXINT 1e9
int minCoins(int coins[],int m, int V){
	int table[V+1];
	table[0]=0;
	fore(i,1,V+1) table[i] = MAXINT;
	fore(i,1,V+1){
		forn(j,m){
			if(coins[j]<=i){
				int sub_res = table[i-coins[j]];
				if(sub_res!=MAXINT && sub_res+1<table[i])
					table[i] = sub_res+1;
			}
		}
	}
	return table[V];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x; cin >> n >> x;
	int coins[n]; forn(i,n) cin >> coins[i];
	int ans = minCoins(coins,n,x);
	if(ans!=MAXINT) cout << ans << endl;
	else puts("-1");
	return 0;
}
