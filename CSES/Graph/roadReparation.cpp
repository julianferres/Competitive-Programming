/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 100005
#define INF 1e18

ll n;int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,pair<int,int> > > es; // edges (cost,(u,v))
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	ll n_unions = 0;
	forr(i,0,es.size()){
		int x=es[i].second.first,y=es[i].second.second;
		if(uf_join(x,y)){r+=es[i].first; 
			n_unions++;
		}// (x,y,c) belongs to mst
	}
	return n_unions==n-1 ? r : -1; // total cost
}


int main()
{
	FIN;
	ll m; cin >> n >> m;
	forn(i,m){
		ll a,b,c; cin >> a >> b >> c; a--,b--;
		es.pb(mp(c,mp(a,b)));
	}
	ll r = kruskal();

	if(r==-1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << r << endl;
	return 0;
}


