/*   AUTHOR: Estufa en Piloto   */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define RAYA cerr << "===============================" << endl
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

bool seen[26];
map<char, int> ch_to_int;

int main(){  
    FIN;

    string s; cin >> s;
    int n = (int) s.size();
    int chars_distintos = 0;


    forn(i, n){
        int c = (int) (s[i] - 'a');
        if(!seen[c]){
            ch_to_int[s[i]] = chars_distintos++;
            seen[c] = true;
        }
    }

    ll ans = 0;
    vector<int> cnt(chars_distintos);
    map<vector<int>, ll> hist = {{cnt, 1}};

    forn(i, n){
        int c = ch_to_int[s[i]];
        cnt[c]++;
        if(all_of(all(cnt), [](int x){ return x >= 1; })){
            forn(j, chars_distintos) cnt[j]--;
        }
        ans += hist[cnt];
        hist[cnt]++;
    }
    
    cout << ans << "\n";

    return 0;
}
