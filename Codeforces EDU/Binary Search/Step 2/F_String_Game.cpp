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
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

bool is_substr(vector<char> s, string t){
    int ps=0, pt=0;
    int n = s.size(); int m = t.size();
    while(ps<n && pt<m){
        if(s[ps]==t[pt]) ps++, pt++;
        else ps++;
    }
    return pt==m;
}

int main(){  
    FIN;
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> borrados(n); forn(i, n) cin >> borrados[i];
    forn(i, n) borrados[i]--;
    int l=0, r=n-1, ans=r;
    while(l<=r){
        int med = (l+r)/2;
        vector<char> aux;
        vector<bool> activos(n, true);
        forn(i, med) activos[borrados[i]] = false;
        forn(i, n) if(activos[i]) aux.pb(s[i]);

        if(is_substr(aux, t)){
            ans = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }

    cout << ans << "\n";
    return 0;
}
