#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl
#define MAXN 200005
int n,q,a,b;
int c,s,x;
vi t[MAXN];
ll initvalue[MAXN];
ll value[MAXN];
ll ans[MAXN];
ll par[MAXN];

void dfs(ll u, ll p){
	for(auto z: t[u]){
		if(z==p) continue;
		par[z]=u;
		dfs(z,u);
		//cnt[u]+=cnt[z];
		//ans[u]+= ans[z]+cnt[z];
	}
}

void modify(ll u, ll delta){
	ll aux=u;
	value[u]+=delta;
	while(aux!=-1){
		ans[aux]+=delta;
		aux = par[aux];
	}
}
void init(){
	bool leaf[MAXN]; forn(i,n) leaf[i]=true;
	fore(i,1,n) leaf[par[i]]=false;
	forn(i,n) ans[i] = value[i];
	forn(i,n) modify(i,initvalue[i]);
}



int main(){ 
    FIN;
    cin >> n >> q;

    forn(i,n) cin >> initvalue[i];
    forn(i,n-1){
    	cin >> a >> b; a--,b--;
    	t[a].pb(b); t[b].pb(a);
    }
    forn(i,n) par[i]=-1;
	dfs(0,0);
	init();
	forn(i,q){
		cin >> c;
		if(c&1){
			cin >> s >> x;s--;
			modify(s,x-value[s]);
		}
		else{
			cin >> s; s--;
			cout << ans[s] << endl;
		}
	}
	return 0;
}