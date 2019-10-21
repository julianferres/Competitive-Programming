#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define MOD 1000000007
 
int main(){ 
	FIN;
	int n,m; cin >> n >> m;
	int a[n]; forn(i,n) cin >> a[i]; forn(i,n) a[i]--;
	int dp[m][n]; forn(i,m)forn(j,n) dp[i][j]=0;

	if(a[0]==-1) forn(i,m) dp[i][0]=1;
	else dp[a[0]][0]=1;


	fore(j,1,n){
		if(a[j]!=-1){
			if(a[j]>0) dp[a[j]][j]+=dp[a[j]-1][j-1];
			dp[a[j]][j]%=MOD;
			if(a[j]<m-1) dp[a[j]][j]+=dp[a[j]+1][j-1];
			dp[a[j]][j]%=MOD;
			dp[a[j]][j]+=dp[a[j]][j-1];
			dp[a[j]][j]%=MOD;
		}
		else{
			forn(i,m){
				if(i>0) dp[i][j]+=dp[i-1][j-1];
				dp[i][j]%=MOD;
				if(i<m-1) dp[i][j]+=dp[i+1][j-1];
				dp[i][j]%=MOD;
				dp[i][j]+=dp[i][j-1];		
				dp[i][j]%=MOD;
			}

		}


	}

	int ans = 0;
	if(a[n-1]==-1) {forn(i,m) ans+=dp[i][n-1],ans%=MOD;}
	else ans = dp[a[n-1]][n-1];
	cout << ans << endl;
	return 0;
}