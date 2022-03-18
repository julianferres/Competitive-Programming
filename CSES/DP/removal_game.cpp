/*input
5
1 2 3 4 5 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define ii pair<int,int>
#define forn(i,n) for(int i=0; i<n; i++)

ll rec(ll** dp,int* a,int l, int r){
	if(l>=r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	return dp[l][r] = max(min(a[l]+rec(dp,a,l+2,r),a[l]+rec(dp,a,l+1,r-1)),min(a[r]+rec(dp,a,l,r-2),a[r]+rec(dp,a,l+1,r-1)));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	ll** dp = new ll *[n+5];

	forn(i,n) dp[i] = new ll[n+5]; 
	forn(i,n)forn(j,n) dp[i][j]=-1LL;
	int a[n]; forn(i,n) cin >> a[i];

	cout << rec(dp,a,0,n-1) << endl;
  	return 0;
}
