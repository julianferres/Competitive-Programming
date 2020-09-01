/*    AUTHOR: julianferres, vie 28 ago 2020 01:12:49 -03 */
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


typedef long long tipo;
 
struct lazy {
  struct node {
    tipo ans, l, r, val=0; //Poner el neutro del update
    int cnt = 0;
    bool upd; tipo INF = (tipo)(1e18+7);
    node base(node aux) {aux.ans=INF; return aux;} //Poner el neutro de la query
    void set_node(tipo x, tipo pos) {ans = x, cnt=1, l = r = pos;};
    void set_lazy(tipo x) {upd=true, val += x;} //Poner operacion de update
    void combine(node a, node b) {
      if(a.ans == b.ans){
          ans = a.ans;
          cnt = a.cnt + b.cnt;
      }
      else{
          ans = min(a.ans, b.ans);
          cnt = a.ans<b.ans ? a.cnt : b.cnt;
      }
      l = min(a.l,b.l); r = max(a.r,b.r);
    }
  };
  vector <node> t; 
  
  void push(tipo p) {
    if(t[p].upd == true) {
      t[p].ans += t[p].val;
      if(t[p].l < t[p].r) {
        t[2*p+1].val += t[p].val; t[2*p+2].val += t[p].val; //Operacion de update
        t[2*p+1].upd = true; t[2*p+2].upd = true;
      }
      t[p].val = 0; t[p].upd = false; //Poner el neutro del update
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


int main(){  
    FIN;
        
    int n; cin >> n;
    vector<tuple<int, int, int, int>> eventos;
    forn(i, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000000;
        y1 += 1000000;
        x2 += 1000000;
        y2 += 1000000;
        eventos.pb({x1, 1, y1, y2-1});
        eventos.pb({x2, -1, y1, y2-1});
    }
    sort(all(eventos));
    vi aux(2e6+10);
    lazy st; st.construir(aux, aux.size());

    ll ans = 0, act = 0;
    forn(i, 2e6+2){
        while(act < eventos.size() && get<0>(eventos[act]) == i){
            st.modificar(get<2>(eventos[act]), get<3>(eventos[act]), get<1>(eventos[act]));
            act++;
        }
        st.push(0);
        int suma_act = aux.size() - st.query(0, aux.size()-1).cnt;
        //if(suma_act) debug() << imie(suma_act);
        ans +=suma_act;
    }

    cout << ans << "\n";
    return 0;
}
