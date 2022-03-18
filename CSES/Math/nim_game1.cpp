#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,n; 
	cin >> t;
	forn(i,t){
		cin >> n;
		int a[n];
		forn(j,n) cin >> a[j];
		int ans = 0;
		forn(j,n) if(j&1) ans^=a[j];
		cout << ans << endl;
		ans ? puts("first"): puts("second");
	}

	return 0;
}
