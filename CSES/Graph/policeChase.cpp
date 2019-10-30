#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

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
#define INF 2000000000
#define MAXN 505
ll n;
vi capacity[MAXN];
vi orgcapacity[MAXN];
vi adj[MAXN];
vi adj1[MAXN];

int visited[MAXN];

void dfs(int v) {
    visited[v] = 1;
    for (int u : adj1[v]) {
        if (!visited[u])
            dfs(u);
    }
}

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


int main(){ 
	FIN;
	ll m; cin >> n >> m;
	forn(i,n){
        vi capp(n,0);capacity[i]=capp;
        vi orgcapp(n,0);orgcapacity[i]=orgcapp;
    }
	forn(i,m){
		ll a,b; cin >> a >> b; a--;b--;
		orgcapacity[a][b]=1; orgcapacity[b][a]=1;
        capacity[a][b]=1; capacity[b][a]=1;
        adj[a].pb(b); adj[b].pb(a);
	}
	ll ans = maxflow(0,n-1);
	cout << ans << endl;
    forn(i,n){
        forn(j,n){if(capacity[i][j]>0) adj1[i].pb(j);}
    }
    dfs(0);

    forn(i,n){
        forn(j,n){
            if(visited[i] && !visited[j] && orgcapacity[i][j]){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
	return 0;
}