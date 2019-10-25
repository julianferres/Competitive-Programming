#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz size()
#define forn(i,n) for(int i=0; i<n; i++)

void bfs(int n, vector<int> ady[], int dist[], int s){
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
	int ans = 0;
	forn(i,n) ans = max(ans,dist2[i]);
	cout << ans << endl;
	return 0;
}
