/*    AUTHOR: julianferres, Mon 14 Sep 2020 07:22:54 PM -03 */
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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;
typedef long double ld;

int ansl = -1, ansr = -1;
int d;

bool check(vector<ld> a, ld x){
    int n = (int) a.size(); forn(i, n) a[i] -= x;
    vector<ld> pre(n+1);
    vector<int> min_pre(n+1);
    forn(i, n) pre[i+1] = pre[i] + a[i];
    min_pre[0] = 0;
    forr(i, 1, n+1) min_pre[i] = (pre[min_pre[i-1]]<=pre[i] ? min_pre[i-1] : i);
    //debug() << imie(x) imie(pre) imie(min_pre);

    forn(i, n+1){
        if(i >= d && pre[min_pre[i-d]] <= pre[i]){
            ansl = min_pre[i-d]+1, ansr = i;
            return true;
        }
    }
    //debug() << imie(x);
    return false;
}
    


int main(){  
    FIN;

    int n; cin >> n >> d;
    vector<ld> a(n); forn(i, n) cin >> a[i];

    
    ld l = 0, r=INF;

    while(r - l >= 1e-6){
        ld med = (l+r+0.0)/2;
        
        if(check(a, med)){
            l = med;
        } else {
            r = med;
        }
    }

    cout << ansl << " " << ansr << "\n";

    return 0;
}
