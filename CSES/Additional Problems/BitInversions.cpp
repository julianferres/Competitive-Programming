/*    AUTHOR: julianferres, mar 18 ago 2020 00:35:04 -03 */
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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;


typedef struct{
    int l0, l1, r0, r1, max0, max1, tam;
} tipo;

tipo combine(tipo a, tipo b){
    tipo ans;
    ans.max0 = max(a.max0, b.max0);
    ans.max1 = max(a.max1, b.max1);
    ans.tam = a.tam + b.tam;
    ans.l1 = a.l1, ans.l0 = a.l0;
    ans.r0 = b.r0, ans.r1 = b.r1;
    if(a.r1 && b.l1){
        if(a.r1 == a.tam)
            ans.l1 = a.r1+b.l1;
        if(b.l1 == b.tam)
            ans.r1 = a.r1+b.l1;
        ans.l0 = a.l0, ans.r0 = b.r0;
        ans.max1 = max(ans.max1, a.r1+b.l1);
    }
    if(a.r0 && b.l0){
        if(a.r0 == a.tam)
            ans.l0 = a.r0+b.l0;
        if(b.l0 == b.tam)
            ans.r0 = a.r0+b.l0;
        ans.l1 = a.l1, ans.r1 = b.r1;
        ans.max0 = max(ans.max0, a.r0+b.l0);
    }
    return ans;
}

tipo create(int x){
    tipo ans;
    ans.l0 = ans.r0 = ans.max0 = !x;
    ans.l1 = ans.r1 = ans.max1 = x;
    ans.tam = 1;
    return ans;
}
tipo neutro(){ tipo ans; return ans; }

vector <tipo> tree(4*MAXN);

void actualizar(int pos){ tree[pos]=combine(tree[2*pos+1],tree[2*pos+2]); }

void construir_segtree(int a, int b, int pos, vector <tipo> &v){
  if(a==b) {tree[pos]=v[a]; return;}
  int med=(a+b)/2;
  construir_segtree(a,med,2*pos+1,v);
  construir_segtree(med+1,b,2*pos+2,v);
  actualizar(pos);
}

void modificar_segtree(int a, int b, int pos, int y, tipo m){
  if(a==b) {tree[pos]=m; return;}
  int med=(a+b)/2;
  if(y<=med) modificar_segtree(a,med,2*pos+1,y,m);
  else modificar_segtree(med+1,b,2*pos+2,y,m);
  actualizar(pos);
}

tipo query_segtree(int a, int b, int x, int y, int pos){
  if(x>b || y<a) return neutro();
  if(x<=a && b<=y) return tree[pos];
  int med=(a+b)/2;
  return combine(query_segtree(a,med,x,y,2*pos+1),query_segtree(med+1,b,x,y,2*pos+2));
}
 
void construir(vector <tipo> &v, int n){ construir_segtree(0,n-1,0,v); }
void modificar(int pos, tipo val, int n){ modificar_segtree(0,n-1,0,pos,val); }
tipo query(int l, int r, int n){ return query_segtree(1,n-1,l,r,0); }

int main(){  
    FIN;
    
    string s; cin >> s;
    int n = s.size();
    vi a(n); forn(i, n) a[i] = s[i] - '0';
    vector<tipo> v(n);
    forn(i, n) v[i] = create(a[i]); 
    construir(v, n);

    int m; cin >> m;
    forn(i, m){
        int idx; cin >> idx;
        idx--; a[idx] ^= 1;
        modificar(idx, create(a[idx]), n);
        tipo ans = query(0, n-1, n);
        cout << max(ans.max0, ans.max1) << " ";
    }
    cout << endl;

    return 0;
} 
