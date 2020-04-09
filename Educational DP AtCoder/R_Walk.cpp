/******************************************
*    AUTHOR:         julianferres         *
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
#define SZ(x) ((int)x.size())
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
const int mod = 1e9 + 7;

typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
	Matrix r(n,vector<ll>(n));
	forn(i,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	forn(i,n)forn(j,m)forn(k,z)
		r[i][j]+=a[i][k]*b[k][j],r[i][j]%=mod;
	return r;
}
Matrix be(Matrix b, ll e) {
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}

void add( ll &a, ll b){
    a += b;
    if(a>=mod)
        a -= mod;
}

int main(){
    FIN;
    ll n,k; cin >> n >> k;

	Matrix g(n,vi(n,0));

	forn(i,n) forn(j,n) cin >> g[i][j];

	Matrix ansMat = be(g,k);

    ll ans = 0;
    forn(i, n) forn(j, n) add(ans, ansMat[i][j]);
    cout << ans << endl;
    return 0;
}

