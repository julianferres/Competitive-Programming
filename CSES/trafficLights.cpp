#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
	int x,n; cin >> x >> n;
	int a[n]; forn(i,n) cin >> a[i];
	set<int> pts; multiset<int,greater <int>> d;
	pts.insert(0),pts.insert(x),d.insert(x);
	forn(i,n){
		auto prox = pts.lower_bound(a[i]);
		auto pr = prev(prox);
		int d1,d2,dold;
		dold = *prox-*pr; d1 = *prox - a[i];
		d2 = a[i]-*pr;
		auto itr = d.find(dold);
		d.erase(itr);d.insert(d1);d.insert(d2);
		cout << *d.begin() << " ";
		pts.insert(a[i]);
	}
	cout << endl;
	return 0;
}