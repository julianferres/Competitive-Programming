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
#define SZ(x) ((int)x.size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int mod = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

typedef vector<vector<ll>> Matrix;
Matrix ones(int n) {
    Matrix r(n,vector<ll>(n));
    forr(i,0,n)r[i][i]=1;
    return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
    int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
    Matrix r(n,vector<ll>(m));
    forr(i,0,n)forr(j,0,m)forr(k,0,z)
        r[i][j]+=a[i][k]*b[k][j],r[i][j]%=mod;
    return r;
}
Matrix be(Matrix b, ll e) {
    Matrix r=ones(SZ(b));
    while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
    return r;
}


int main() {
    FIN;

    ll n, k; cin >> n >> k;
    Matrix t(n+3, vi(n+3));
    Matrix res(n+3, vi(1));

    vi a(n), coefs(n);
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> coefs[i];

    ll p, q, r; cin >> p >> q >> r;
    
    if(k<=n-1){
        cout << a[k] << "\n";
        return 0;
    }

    forn(i,n) res[i][0] = a[n-1-i];
    res[n][0] = 1; res[n+1][0] = n; res[n+2][0] = n*n;

    forn(i,n) t[0][i] = coefs[i];
    t[0][n] = p, t[0][n+1] = q, t[0][n+2] = r;

    forr(i,1,n) t[i][i-1] = 1;
    t[n][n] = 1;
    t[n+1][n] = 1, t[n+1][n+1] = 1;
    t[n+2][n] = 1, t[n+2][n+1] = 2, t[n+2][n+2] = 1;

    Matrix pot = be(t, k-(n-1));
    res = pot * res;
    cout << res[0][0] << "\n";


    return 0;
}
