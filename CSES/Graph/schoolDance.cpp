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
#define MAXN 605
ll n,m;
vi capacity[2*MAXN+3];
vi orgcapacity[2*MAXN+3];
vi adj[2*MAXN+3];

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
    vector<ll> parent(n+m+2);
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
    ll k; cin >> n >> m >> k;
    forn(i,n+m+2){
        vi capp(n+m+2,0);capacity[i]=capp;
    }
    fore(i,1,n+1){
        capacity[0][i]=1;
        //capacity[i][0]=1LL;
        adj[0].pb(i);
        adj[i].pb(0);
    }
    fore(i,n+1,n+m+1){
        capacity[i][n+m+1]=1;
        //capacity[n+m+1][i]=1;
        adj[i].pb(n+m+1);
        adj[n+m+1].pb(i);
    }
    set <pair<int,int>> seen;
    forn(i,k){
        ll a,b; cin >> a >> b;
        if(seen.find(mp(a,b)) != seen.end())
            continue;
        seen.insert(mp(a,b));
        //capacity[b+n][a]=1;
        capacity[a][b+n]=1;
        adj[a].pb(b+n);
        adj[b+n].pb(a);
    }
    /*
    forn(i,n+m+2){
        forn(j,adj[i].sz) cout << adj[i][j] << " ";
        cout << endl;
    }
    RAYA;*/
    ll ans = maxflow(0,n+m+1);
    cout << ans << endl;

    fore(i,1,n+1)
        forn(j,adj[i].sz){
                if(adj[i][j]!=0 && !capacity[i][adj[i][j]])
                    cout << i << " " << adj[i][j]-n << endl;
        }
    return 0;
}