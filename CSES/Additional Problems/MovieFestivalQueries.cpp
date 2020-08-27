/*    AUTHOR: julianferres, jue 27 ago 2020 12:46:16 -03 */
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
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;
 
int jump[MAXN][20];
 
int main(){  
    FIN;
    int n, q; cin >> n >> q;
    forn(i, MAXN) jump[i][0] = MAXN-1;
 
    forn(i, n){
        int l, r; cin >> l >> r;
        jump[l][0] = min(jump[l][0], r);
    }
    for(int i = MAXN-1; i>=1; i--){
        jump[i-1][0] = min(jump[i-1][0], jump[i][0]);
    }
    forr(j, 1, 20) forn(i, MAXN) jump[i][j] = jump[jump[i][j-1]][j-1];
    forn(i, q){
        int l, r; cin >> l >> r;
        int ans = 0;
        for(int j=19; j>=0; j--){
            if(jump[l][j] <= r){
                ans +=  1<<j;
                l = jump[l][j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
