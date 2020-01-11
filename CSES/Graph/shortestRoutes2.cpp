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

int n; 
int main()
{
    FIN;
    int m,q; cin >> n >> m >> q;
    ll g[n+5][n+5];
    forn(i,n) forn(j,n) g[i][j] = INF;
    forn(i,n) g[i][i] = 0;
    forn(i,m){
        ll a,b,cost; cin >> a >> b >> cost;
        a--; b--; 
        g[a][b] = g[b][a] = min(cost,g[a][b]);
    }

    forn(k,n)forn(i,n)forn(j,n) g[i][j] = min(g[i][j],g[i][k]+g[k][j]);

    forn(i,q){
        int a,b; cin >> a >> b;
        ll dist = g[a-1][b-1] != INF ? g[a-1][b-1] : -1;
        cout << dist << endl;
    }

    return 0;
}

