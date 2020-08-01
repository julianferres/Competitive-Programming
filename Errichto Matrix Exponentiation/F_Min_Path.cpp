/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz size()
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll INF = 1LL<<60;
const int mod = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

typedef vector<vector<ll> > Matrix;

Matrix operator*(Matrix &a, Matrix &b){
    int n=a.sz, m = b[0].sz, z = a[0].sz;
    Matrix r(n,vector<ll>(m, INF));
    forn(i,n){
        forn(j,m){
            forn(k,z){
                if(a[i][k] != INF && b[k][j]!=INF)
                    r[i][j]= min(r[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return r;
}
Matrix be(Matrix b, ll e){
    Matrix r = b;
    while(e){if(e&1LL) r=r*b;b=b*b;e/=2;}
    return r;
}
 
int main()
{
    FIN;
    ll n,m,k; cin >> n >> m >> k;
    Matrix g(n,vector<ll>(n));
    forn(i,n) forn(j,n) g[i][j]=INF;
    forn(i,m){
        ll a,b,c; cin >> a >> b >> c;
        g[a-1][b-1] = c;
    }
    Matrix ansMat = be(g,k-1);
    ll ans = INF;
    forn(i,n) forn(j,n) ans = min(ans, ansMat[i][j]);
    if(ans==INF) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;
    return 0;
}