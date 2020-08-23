/*    AUTHOR: julianferres, vie 21 ago 2020 19:37:43 -03 */
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
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const ll INF = 1LL<<40;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

vi ok(vector<tuple<int, int, int>> a, ll med){
    vi ans(a.size());
    forn(i, a.size()){
        int t, z, y;
        tie(t, z, y) = a[i];
        ans[i] = (med/(z*t+y))*z;
        ll restante = med%(z*t+y);
        ans[i] += ((restante>=z*t) ? z : restante/t);
    }
    return ans;
}

int main(){  
    FIN;
    int m, n; cin >> m >> n;
    vector<tuple<int, int, int>> a;
    forn(i, n){
        int t, y, z; cin >> t >> z >> y;
        a.pb({t,z,y});
    }
    ll l=0, r=INF, ans=r;
    vi ans_vec;
    while(l<=r){
        ll med = (l+r)/2;
        vi aux = ok(a, med);
        ll suma = 0; forn(i, n) suma+=aux[i];

        if(suma>=m){
            r = med-1;
            ans = med;
            ans_vec = aux;
        }
        else l = med+1;
    }
    
    //debug() << imie(ans_vec);
    cout << ans << "\n";
    ll cum = 0;
    forn(i, n){
        if(cum==m) cout << "0 ";
        else if(cum+ans_vec[i]<=m){
            cout << ans_vec[i] << " ";
            cum+= ans_vec[i];
        }
        else{
            cout << m-cum << " ";
            cum = m;
        }
    }
    return 0;
}
