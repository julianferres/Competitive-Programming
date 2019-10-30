#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef multiset<ll> si;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

int main(){ 
	FIN;
	si s; ll x,n; cin >> x >> n;
	forn(i,n){ll a; cin >> a; s.insert(a);}
	ll ans = 0;
	forn(i,n-1){
		auto fst = s.begin(); s.erase(fst);
		auto snd = s.begin(); s.erase(snd);
		ans+= *fst+*snd;
		s.insert(*fst+*snd);
	}
	cout << ans << endl;

	return 0;
}