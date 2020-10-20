/*    AUTHOR: julianferres, Tue 15 Sep 2020 05:54:30 PM -03 */
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

int par[MAXN], sz[MAXN];
vector<tuple<int, int, int, int, int>> logs; //y, old_par[y], x, old_sz[x], old_cc
vector<int> checkpoints(1, 0); //Cantidad de operaciones previas a tal checkpoint
int cc;

int find(int x){
    while(par[x] != x) x = par[x];
    return x;
}
void join(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    logs.pb({y, par[y], x, par[x], cc});
    par[y] = x; sz[x] += sz[y];
    cc--;
}
void rollback(){
  int check = checkpoints.back();
            if(check) checkpoints.pop_back();
            
            while((int)logs.size() > check){
                int y, old_par_y, x, old_sz_x, old_cc;
                tie(y, old_par_y, x, old_sz_x, old_cc) = logs.back();
                logs.pop_back();
                par[y] = old_par_y; sz[x] = old_sz_x;
                cc = old_cc;
            }
}
void persist(){ checkpoints.pb((int) logs.size()); }


const int block_size = 200;
vector<pair<int, int>> edges;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main(){  
    FIN;
    int n, m; cin >> n >> m;
    edges.resize(m);
    forn(i, m) cin >> edges[i].first >> edges[i].second;

    forn(i, n+1) par[i] = i, sz[i] = 1;
    cc = n;

    int k; cin >> k;
    vector<Query> q;
    forn(i, k){
        int l, r; cin >> l >> r;
        q.pb({l, r, i});
    }

    vector<int> ans = mo_s_algorithm(q);

    for(int ansi: ans) cout << ansi << "\n";

    return 0;
}
