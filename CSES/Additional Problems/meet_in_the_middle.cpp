#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define RAYA cerr << "===============================" << endl

void rec(vi &a,ll S,vi &v,ll pos,ll aux){
	if(pos==a.size()){if(aux!=0) v.pb(aux);return;}
	rec(a,S,v,pos+1,aux);
	if(aux+a[pos]<=S) rec(a,S,v,pos+1,aux+a[pos]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,S;
	cin >> n >> S;
	vi x,y; x.pb(0);y.pb(0);

	ll p=n/2,q=n-n/2;
	vi a(p),b(q);
	forn(i,p) cin >> a[i];
	forn(i,q) cin >> b[i];
	rec(a,S,x,0,0); rec(b,S,y,0,0);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	ll ans = 0;
	for(ll u : x){
		ans+=lower_bound(y.begin(), y.end(),S-u+1)-lower_bound(y.begin(), y.end(),S-u);
	}
	cout << ans << endl;
	return 0;
}
