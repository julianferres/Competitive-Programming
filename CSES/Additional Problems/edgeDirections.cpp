#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef vector<bool> vb;

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
#define MAXN 100005
int n,m;
vi adj[MAXN];
bool visited[MAXN];
vi ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}


int main(){ 
	FIN;
    cin >> n >> m;
    vii edges;
    forn(i,m){
        ll a,b; cin >> a >> b;a--;b--;
        edges.pb(mp(a,b));
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(0);
    vi order(n,0);
    forn(i,ans.size()){
        order[ans[i]]=i;
    }
    forn(i,edges.size()){
        ll f = edges[i].first, s = edges[i].second;
        if(order[f]<order[s])
            cout << f+1 << " " << s+1 << endl;
        else
            cout << s+1 << " " << f+1 << endl;
    }



	return 0;
}