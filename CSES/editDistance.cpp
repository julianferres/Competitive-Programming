#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define MAXINT 50000
int min(int x, int y, int z){
	return min(x,min(y,z));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s,t; cin >> s >> t;
	int n=s.sz,m=t.sz;
	int dp[n+1][m+1];

	forn(i,n+1)
		forn(j,m+1){
			if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;
			else if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]= min(dp[i][j-1],dp[i-1][j-1],dp[i-1][j])+1;
		}
	cout << dp[n][m] << endl;
	return 0;
}
