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

ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b>0){
        if(b&1) res = res*a % m;
        a = a*a % m;
        b >>= 1;
    }
    return res;
}

ll invmod(ll a, ll m){
    return (binpow(a,m-2,m)+m)%m;
}

int main(){
    ll M = 1000000007;
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> fact;
    fact.pb(1LL); fore(i,1,2000004) fact.pb((fact.back()*i)%M);

    ll n,m; cin >> n >> m;
    ll a = n+m-1; ll b = m;

    cout << (fact[a]*invmod(fact[b],M)%M)*invmod(fact[a-b],M)%M << endl;


    return 0;
}
