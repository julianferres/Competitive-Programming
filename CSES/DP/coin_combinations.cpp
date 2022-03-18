#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define MOD 1000000007
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin >> n >> x;
  
  int coins[n]; 
  forn(i,n) cin >> coins[i];

  int dp[x+5]; forn(i,x+1) dp[i]=0; dp[0] = 1;
  forn(i,x+1){
  	forn(j,n){
  		if(i+coins[j]<x+1){
        dp[i+coins[j]] += dp[i];
  		  dp[i+coins[j]]%=MOD;
      }
  	}
  }
  if(x<coins[0]) cout << "0\n";
  else cout << dp[x]%MOD << endl;
  return 0;
}

