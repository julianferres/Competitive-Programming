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
#define MAXN 100005
#define MOD 1000000007

vi g[MAXN];int n;
vi tsort(){  // lexicographically smallest topological sort
	vi r;priority_queue<ll> q;
	vi d(2*n,0);
	forn(i,n)forn(j,g[i].size())d[g[i][j]]++;
	forn(i,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		forn(i,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(-g[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}



int main()
{
    FIN; int m;
    cin >> n >> m;
    forn(i,m){
        ll a,b; cin >> a >> b;
        g[a-1].pb(b-1);
    }
    ll ways[n]; forn(i,n) ways[i]=0LL;
    ways[0] = 1;
    vi t_sort = tsort();
    //reverse(all(t_sort));
    forn(i,n){
        ll act = t_sort[i];
        for(auto e: g[act]){
           ways[e]+= ways[act];
           ways[e]%=MOD;
        }
    }
    cout << ways[n-1] << endl;

    return 0;
}

