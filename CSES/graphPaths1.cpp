#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define MOD 1000000007
typedef vector<vector<ll> > Matrix;
 
Matrix ones(int n){
	Matrix r(n,vector<ll>(n));
	forn(i,n) r[i][i] = 1LL;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b){
	int n=a.sz, m = b[0].sz, z = a[0].sz;
	Matrix r(n,vector<ll>(m));
	forn(i,n) forn(j,m) forn(k,z)
		r[i][j]+= a[i][k]*b[k][j],r[i][j]%=MOD;
	return r;
}
Matrix be(Matrix b, ll e){
	Matrix r=ones(b.sz);
	while(e){if(e&1LL) r=r*b;b=b*b;e/=2;}
	return r;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,k; cin >> n >> m >> k;
	Matrix g(n,vector<ll>(n));
	forn(i,m){
		int a,b; cin >> a >> b;
		g[a-1][b-1]++;
	}
	Matrix ansMat = be(g,k);
	cout << ansMat[0][n-1] << endl;
	return 0;
}
