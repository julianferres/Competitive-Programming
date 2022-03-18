#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define MOD 1000000007
typedef vector<vector<ll> > Matrix;
const ll MAXINT = 20000000000;
Matrix operator*(Matrix &a, Matrix &b){
	int n=a.sz, m = b[0].sz, z = a[0].sz;
	Matrix r(n,vector<ll>(m));
	forn(i,n){
		forn(j,m){
			r[i][j] = a[i][0]+b[0][j];
			forn(k,z){
				r[i][j]= min(r[i][j],a[i][k]+b[k][j]);r[i][j];
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,k; cin >> n >> m >> k;
	Matrix g(n,vector<ll>(n));
	forn(i,n) forn(j,n) g[i][j]=MAXINT;
	forn(i,m){
		ll a,b,c; cin >> a >> b >> c;
		g[a-1][b-1]=min(g[a-1][b-1],c);
	}
	Matrix ansMat = be(g,k-1);
	if(ansMat[0][n-1]==MAXINT) cout << "-1" << endl;
	else cout << ansMat[0][n-1] << endl;
	return 0;
}
