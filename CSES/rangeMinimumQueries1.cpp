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

const int MAXN = 10e5+5;
const int K = 25;
ll st[MAXN][K];
int Log[MAXN+1];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Log[1]=0;
	fore(i,2,MAXN+1) Log[i]=Log[i/2]+1;

	int n,q; cin >> n >> q; 
	int a[n]; forn(i,n) cin >> a[i];
	forn(i,n) st[i][0]=a[i];
	fore(j,1,K+1)
		forn(i,n-(1<<j)+1)
			st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	
	forn(i,q){
		int l,r; cin >> l >> r;l--;r--;
		int j = Log[r-l+1];
		cout << min(st[l][j],st[r-(1<<j)+1][j]) << endl;;
	}
	

	return 0;
}
