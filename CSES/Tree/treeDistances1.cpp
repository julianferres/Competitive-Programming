#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
#define sz size()
#define forn(i,n) for(int i=0; i<n; i++)
#define MAXN 200005

vi bfs(int n, vector<int> ady[], int dist[], int s){
	queue<int> q;
	bool vis[n]={false};
	vi parent(n,-1);
	q.push(s); vis[s]=true; dist[s]=0;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto u: ady[v]){
			if(!vis[u]){
				parent[u]=v;
				vis[u]=true;
				q.push(u);
				dist[u]=dist[v]+1;
			}
		}
	}
	return parent;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> t[n];
	forn(i,n-1){
		int a,b; cin >> a >> b; a--;b--;
		t[a].pb(b);t[b].pb(a);
	}
	int dist1[n]={0};
	bfs(n,t,dist1,0);

	int M=0,Midx=0;
	forn(i,n){
		if(dist1[i]>M){
			M = dist1[i]; Midx=i;
		}
	}
	int dist2[n]={0};
	bfs(n,t,dist2,Midx);
	int Nidx=0; M = 0;
	forn(i,n){
		if(dist2[i]>M){
			M = dist2[i]; Nidx=i;
		}
	}
	int dist3[n]={0};
	bfs(n,t,dist3,Nidx);
	int ans[n];
	forn(i,n) ans[i] = max(dist2[i],dist3[i]);
	forn(i,n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
