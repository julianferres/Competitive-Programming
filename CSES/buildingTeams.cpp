#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> adj[n+5];
    forn(i,m){
        int a,b; cin >> a >> b;
        adj[a-1].pb(b-1); adj[b-1].pb(a-1);
    }

    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    if(is_bipartite){
        forn(i,n) cout << side[i]+1 << " ";
        cout << endl;
    }
    else puts("IMPOSSIBLE");
    return 0;
}

