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
 	int n; cin >> n;
 	ll a[n]; forn(i,n) cin >> a[i];
 	sort(a, a+n);
 	ll ult = a[n-1] ; ll sum=0;
 	forn(i,n-1) sum+= a[i];

 	cout << ult + max(ult,sum) << endl;
	return 0;
}
