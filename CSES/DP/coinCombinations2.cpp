#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a;i<b;i++)
#define MOD 1000000007

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x; cin >> n >> x;
  int coins[n]; vector<int> dp(x+1); dp[0]=1;
  forn(i,n) cin >> coins[i];
  for(auto c:coins) fore(i,1,x+1) if(c<=i) dp[i]=(dp[i]+dp[i-c])%MOD;
  cout << (dp[x]+MOD)%MOD << endl;
  return 0;
}

