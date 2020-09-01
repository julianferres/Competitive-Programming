/*    AUTHOR: julianferres, vie 28 ago 2020 15:16:23 -03 */
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

int cnt[26];
string ans;

bool check() {
    int total = 0, max_char = 0;
    forn(i,26) {
        max_char = (cnt[i] > cnt[max_char]) ? i : max_char;
        total += cnt[i];
    }
    if (2*cnt[max_char]-1 == total && !(ans.size() && (ans.back()-'A') == max_char)) return true;
    if (2*cnt[max_char] <= total) return true;
    return false;
}

int main(){  
    FIN;

    string s; cin >> s;
    for(char c: s) cnt[c-'A']++;
    if(!check()){
        cout << "-1\n";
        return 0;
    }

    while(ans.size() < s.size()){
        forn(i, 26){
            if(cnt[i]){
                if(ans.size() && ans.back()-'A' == i) continue;
                ans += char('A'+ i); cnt[i]--;
                if(check()) break;
                ans.pop_back(); cnt[i]++;
            }
        }
    }
    cout << ans << "\n";


    return 0;
}
