#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MOD 1000000007

int main(){ 
    FIN;
    ll n; cin >> n;
    vi a; 
    a.pb(1);a.pb(1);a.pb(0);a.pb(0);a.pb(2);
    fore(i,5,n+1){ 
    	a.pb((((i+1)*a[i-1]-(i-2)*a[i-2]-(i-5)*a[i-3]+(i-3)*a[i-4])%MOD+MOD)%MOD);
    }
    cout << a[n] << endl;

    return 0;
}

