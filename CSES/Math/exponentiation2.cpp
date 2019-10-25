#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define forn(i,n) for(ll i=0; i<n; i++)

ll binpow(ll a, ll b, ll m){
	ll res = 1LL;
	while(b>0){
		if(b&1) res = res*a % m;
		a = a*a % m;
		b >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll m = 1000000007;
	int t; cin >> t;

	forn(i,t){
		ll a,b,c; cin >> a >> b >> c;
		cout << binpow(a,binpow(b,c,m-1),m) << endl;
	}

	return 0;
}
