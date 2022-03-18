/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 100005
#define INF 1e18

bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	forr(i,0,n)if(!idx[i])tjn(i);
}


bool visited[MAXN];
void dfs(int v){
    visited[v] = true;
    for (int u: g[v]){
        if(!visited[u]) dfs(u);
    }
}

int main()
{
    FIN;
    int m; cin >> n >> m;
    forn(i,m){
        int a,b; cin >> a >> b;
        g[a-1].pb(b-1);
    }
    scc();
    if(qcmp==1){
        cout << "YES\n" << endl;
        return 0;
    }
    cout << "NO" << endl;
    int segundo_v = 1;
    while(cmp[0]==cmp[segundo_v]) segundo_v++;
    forn(i,n) visited[i] = false;
    dfs(segundo_v);

    if(visited[0]){
        cout << 1 << " " << segundo_v+1 << endl;
    }
    else{
        cout << segundo_v+1 << " " << 1 << endl;
    }    
    return 0;
}

