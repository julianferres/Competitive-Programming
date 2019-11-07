#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

vector<int> g[MAXN];int n;
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g[i].size())d[g[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(-g[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}


int main(){ 
    FIN;
    int m; cin >> n >> m;
    forn(i,m){
        int a,b; cin >> a >> b; a--,b--;
        g[a].pb(b);	
    }
    vi ans = tsort();
    if(ans.size()<n)
    	puts("IMPOSSIBLE");
   	else{
   		forn(i,n) cout << ans[i]+1 << " ";
   		cout << endl;
   	}
	return 0;
   	
}