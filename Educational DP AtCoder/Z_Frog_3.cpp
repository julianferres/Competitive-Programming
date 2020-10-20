/*    AUTHOR: julianferres, Tue 20 Oct 2020 01:13:56 AM -03 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+10; // const ll INF = 1e18+10;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;


// Convex Hull Trick For Maximum
// Para Minimum cambiar los menores por mayores en get y add_line
typedef __int128 ull;
typedef ll tipo;

struct punto {
  tipo x, y;
  punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
  punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
  tipo const operator *(const punto &p) const {return x*p.x + y*p.y;}
  ull const operator /(const punto &p) const { // Producto Cruz
    return (ull)x*(ull)p.y - (ull)y*(ull)p.x; } // (ull) --> __int128
};

vector <punto> hull; // Remember push case base {0,0}

ll get(tipo x) {
	punto query = {x,1LL}; int a=0, b=hull.size();
	while(b-a > 1) {
		int med = (a+b)/2;
    if(query * hull[med-1] > query * hull[med]) a = med;
		else b = med; 
	}
	return query * hull[a];
}

void add_line(ll x, ll y) {
  punto aux = {x,y}; int last = hull.size()-1;
  while(last > 0 && (hull[last]-hull[last-1]) / (aux-hull[last]) > 0) {
    hull.pop_back(); last--;
  }
  hull.pb(aux);
}

int main(){  
    FIN;

    ll n, c; cin >> n >> c;
    
    //cost[i] = C + hi^2 + min(cost[j] + hj^2 - 2*hi*hj);
    
    forn(i, n){
        ll h; cin >> h;
        if(i == 0){
            add_line(-2*h, h*h);
            continue;
        }
    
        ll act = get(h);
        act = c + h*h + act;

        add_line(-2*h, act + h*h);

        if(i==n-1) cout << act << "\n";
    }
    

    return 0;
}


