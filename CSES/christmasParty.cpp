#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define MOD 1000000007
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	ll dp[n+1]; dp[0]=1,dp[1]=0;
	fore(i,2,n+1) dp[i]=(i-1)*(dp[i-1]+dp[i-2])%MOD;
	cout << dp[n] << endl;
	return 0;
}
