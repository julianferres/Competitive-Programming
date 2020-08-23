/*    AUTHOR: julianferres, dom 23 ago 2020 00:29:07 -03 */
#include <bits/stdc++.h>
using namespace std;

// DEBUGGER
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//END DEBUGGER

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const ll INF = 1e14;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

int main(){  
    FIN;
    
    string s; cin >> s;
    ll nb, ns, nc; cin >> nb >> ns >> nc;
    ll pb, ps, pc; cin >> pb >> ps >> pc;
    ll rublas; cin >> rublas;
    vi cnt(3,0); 
    forn(i, s.size()){
        if(s[i]=='B') cnt[0]++;
        if(s[i]=='S') cnt[1]++;
        if(s[i]=='C') cnt[2]++;
    }

    ll ans = 0, l = 0, r = INF;
    while(l<=r){
        ll med = (l+r)/2;
        //debug() << imie(med);
        ll precio = 0;
        precio += max(0LL, cnt[0]*med-nb)*pb;
        precio += max(0LL, cnt[1]*med-ns)*ps;
        precio += max(0LL, cnt[2]*med-nc)*pc;


        if(precio<=rublas)
            ans = med, l = med + 1;
        else r = med-1;
    }
    cout << ans << "\n";

    return 0;
}
