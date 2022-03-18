#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
#define MAXN 200005
ll n,q;
vvi adj(MAXN);
int dist[MAXN]={0};

void bfs(int n, vvi ady, int dist[], int s){
	queue<int> q;
	bool vis[n]={false};
	q.push(s); vis[s]=true; dist[s]=0;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto u: ady[v]){
			if(!vis[u]){
				vis[u]=true;
				q.push(u);
				dist[u]=dist[v]+1;
			}
		}
	}
}

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};


int main(){ 
    FIN;
    cin >> n >> q;
    forn(i,n-1){
    	ll a,b; cin >> a >> b; a--; b--;
    	adj[a].pb(b); adj[b].pb(a);
    }
    bfs(n,adj,dist,0);
    struct LCA consultas = LCA(adj);
    forn(i,q){
    	ll n1,n2; cin >> n1 >> n2; n1--; n2--;
    	int ancestro  = consultas.lca(n1,n2);
    	cout << dist[n1]+dist[n2]-2*dist[ancestro] << endl;
    }



    return 0;
}