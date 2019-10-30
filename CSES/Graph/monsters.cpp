#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef queue<ll> qi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

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
#define MAXN 1000005

vi adj[MAXN];  // adjacency list representation
int n,m; // Matrix dims
int s; // source vertex
int dst; // dest vertex
qi q;
vb usedM(MAXN); vi dM(MAXN), pM(MAXN);
vb usedA(MAXN); vi dA(MAXN), pA(MAXN);

void BFS(vi &sources, vi &d, vi &p,vb &used){
	for(auto s: sources){
    	q.push(s);
    	used[s] = true;
    	p[s] = -1;
	}

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    forn(i,n*m) if(!used[i]) d[i]=MAXN;
}

void SSSP(){
    if (!usedA[dst]) {
    cout << "NO" << endl;
    }
    else {
        vector<int> path;
        for (int v = dst; v != -1; v = pA[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.sz-1 << endl;
        fore(i,1,path.sz){
            int ant=path[i-1],act=path[i];
            if(act==ant+1) cout << "R";
            else if(act==ant-1) cout << "L";
            else if(act==ant+m) cout << "D";
            else cout << "U";
        }
        cout << endl;
    }
}



int main(){ 
    FIN;
    cin >> n >> m;
    vvb a(n);
    vi bordes;
    vi monsters;
    forn(i,n){
        a[i]=vb(m,false);
        forn(j,m){
            char b; cin >> b;
            if(b!='#'){
            	a[i][j]=true;
            	if(j==0 || j==m-1 || i==0 || i==n-1)
            		bordes.pb(i*m+j);
            }
            if(b=='A') s = i*m+j;
            if(b=='M') monsters.pb(i*m+j);
        }
    }
    forn(i,n)
        forn(j,m){
            if(j<m-1 && a[i][j] && a[i][j+1]){
                adj[i*m+j].pb(i*m+j+1);adj[i*m+j+1].pb(i*m+j);
            }
            if(i<n-1 && a[i][j] && a[i+1][j]){
                adj[i*m+j].pb((i+1)*m+j);adj[(i+1)*m+j].pb(i*m+j);
            }
        }
    BFS(monsters, dM, pM , usedM);
    vi via; via.pb(s);
    BFS(via, dA, pA , usedA);
    forn(i,bordes.sz){
    	if(dA[bordes[i]]<dM[bordes[i]]){
    		dst = bordes[i];
    		SSSP();
    		return 0;
    	}
    }
    cout << "NO\n";
    return 0;
}