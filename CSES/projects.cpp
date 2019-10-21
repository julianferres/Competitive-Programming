#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;
typedef vector<ll> vi;
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
	ll n,x,y,z; cin >> n;
	viii a(n);
	vi c(n); //DP, mejor eleccion hasta el cierre de n
	forn(i,n){
		cin >> x >> y >> z;
		a[i] = make_tuple(y,x,z);
	}
	sort(a.begin(), a.end());
	c[0] = get<2>(a[0]); 
	fore(i,1,n){
		tie(y,x,z) = a[i];
		int k = lower_bound(a.begin(), a.end(), make_tuple(x,0,0))-a.begin()-1;
		//Encuentro el mejor que termine antes de x
		ll aux = c[i-1]; //Podria no usar el actual
		aux = (k>=0) ? max(aux,c[k]+z) : max(aux,z);
		c[i]= aux;
	}
	cout << c[n-1] << endl;

	return 0;
}