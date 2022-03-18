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
#define RAYA cerr << "===============================" << endl
#define MAXN 200005
vi t[MAXN];
int n,a,b;
ll cnt[MAXN];
ll ans[MAXN]={0};

void dfs(ll u, ll p){
	for(auto z: t[u]){
		if(z==p) continue;
		dfs(z,u);
		cnt[u]+=cnt[z];
		ans[u]+= ans[z]+cnt[z];
	}
}
void dfsopp(ll u, ll p){
	for(auto z: t[u]){
		if(z==p) continue;
		ans[z] = ans[u]-cnt[z]+(n-cnt[z]);
		dfsopp(z,u);
	}
}


int main(){ 
    FIN;
    cin >> n;
    forn(i,n-1){
    	cin >> a >> b; a--,b--;
    	t[a].pb(b); t[b].pb(a);
    }
	forn(i,n) cnt[i]=1;
	dfs(0,0);
    dfsopp(0,0);
    forn(i,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}