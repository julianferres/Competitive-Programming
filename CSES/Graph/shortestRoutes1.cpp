#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define MAXN 1000005
vector<pair<int,int>> g[MAXN]; // u->[(v,cost)]
ll dist[MAXN];

void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue< pair<ll,int> > q;
	dist[x]=0;q.push(mp(0,x));
	while(!q.empty()){
		x=q.top().S;ll c=-q.top().F;q.pop();
		if(dist[x]!=c) continue;
		fore(i,0,g[x].sz){
			int y=g[x][i].F; ll c=g[x][i].S;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push(mp(-dist[y],y));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	forn(i,m){
		int a,b,c; cin >> a >> b >> c;
		g[a].pb(mp(b,c));
	}
	dijkstra(1);
	fore(i,1,n+1){
		cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}
