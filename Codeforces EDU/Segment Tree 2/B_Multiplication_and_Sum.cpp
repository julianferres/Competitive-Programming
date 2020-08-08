/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
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

typedef long long tipo;
 
struct lazy {
  struct node {
    tipo ans, l, r, val=1;
    bool upd; tipo INF = (tipo)(1e18+7);
    node base(node aux) {aux.ans=0; return aux;}
    void set_node(tipo x, tipo pos) {ans = x, l = r = pos;};
    void set_lazy(tipo x) {upd=true, val *= x; val%=MOD;}
    void combine(node a, node b) {
      ans = a.ans + b.ans;
      ans %= MOD;
      l = min(a.l,b.l); r = max(a.r,b.r);
    }
  };
  vector <node> t; 
  
  void push(tipo p) {
    if(t[p].upd == true) {
      t[p].ans *= t[p].val;
      t[p].ans %= MOD;
      if(t[p].l < t[p].r) {
        t[2*p+1].val *= t[p].val; t[2*p+2].val *= t[p].val;
        t[2*p+1].val %= MOD; t[2*p+2].val %= MOD;
        t[2*p+1].upd = true; t[2*p+2].upd = true;
      }
      t[p].val = 1; t[p].upd = false;
    }
  }
  
  node ask(int p, tipo l, tipo r) {
    push(p); 
    if(l > t[p].r || r < t[p].l) return t[p].base(t[p]);
    if(l <= t[p].l && t[p].r <= r) return t[p];
    node ans; ans.combine(ask(2*p+1,l,r),ask(2*p+2,l,r));
    return ans;
  }
  
  void update(int p, tipo l, tipo r, tipo val) {
    push(p); 
    if(l > t[p].r || r < t[p].l) return;
    if(l <= t[p].l && t[p].r <= r) {
      t[p].set_lazy(val); push(p);
      return;
    }
    update(2*p+1, l, r, val); update(2*p+2, l, r, val);
    t[p].combine(t[2*p+1], t[2*p+2]);
  }
  
  void build(tipo a, tipo b, int p, vector <tipo> &v) {
    if(a==b) {t[p].set_node(v[a],a); return;}
    tipo med=(a+b)/2;
    build(a, med, 2*p+1, v); build(med+1, b, 2*p+2, v);
    t[p].combine(t[2*p+1], t[2*p+2]);
  }
  node query(tipo l, tipo r) {return ask(0,l,r);}
  void modificar(tipo l, tipo r, tipo val) {update(0,l,r,val);}  
  void construir(vector <tipo> &v, int n) { t.resize(4*n); build(0,n-1,0,v); }
};


int main() {
    FIN;

    int n, m; cin >> n >> m;

    vi a(n, 1);
    lazy st;
    st.construir(a, n);

    forn(i, m){
        int tipo; cin >> tipo;
        if(tipo == 1){ 
            int l, r,value; cin >> l >> r >> value;
            st.modificar(l, r-1, value);
        }
        else{
            int l, r; cin >> l >> r;
            cout << st.query(l, r-1).ans << "\n";
        }
    }

    

    return 0;
}