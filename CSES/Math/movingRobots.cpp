#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define pb push_back
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define MOD 1000000007
typedef vector<vector<ld> > Matrix;
 
Matrix ones(int n){
	Matrix r(n,vector<ld>(n));
	forn(i,n) r[i][i] = 1.0;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b){
	int n=a.sz, m = b[0].sz, z = a[0].sz;
	Matrix r(n,vector<ld>(m));
	forn(i,n) forn(j,m)	forn(k,z) r[i][j]+= a[i][k]*b[k][j];
	return r;
}
Matrix be(Matrix b, ll e){
	Matrix r=b;
	while(e){if(e&1) r=r*b;b=b*b;e/=2;}
	return r;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll k; cin >> k;
	Matrix tr(64,vector<ld>(64));
	forn(i,64){ 
		//Lleno matriz de transicion
		// tr[i][j], aporte de j hacia i 
		//(por ejemplo tr[0][8]=1/3,tr[0][1]=1/3)
		int ady = 0;
		if(i>=8) ady++;
		if(i%8!=0) ady++;
		if(i%8!=7) ady++;
		if(i<56) ady++;
		if(i>=8) tr[i-8][i]=1.0/ady;
		if(i%8!=0) tr[i-1][i]=1.0/ady;
		if(i%8!=7) tr[i+1][i]=1.0/ady;
		if(i<56) tr[i+8][i]=1.0/ady;
	}
	Matrix ans =be(tr,k-1);

	ld ECasFree = 0.0;
	forn(i,64){
		ld pCasFree = 1.0;
		forn(r,64) pCasFree*=(1.0-ans[i][r]);
		//Ningun robot tiene que estar en i;
		ECasFree+=pCasFree;
	}
	cout << fixed << setprecision(6)<< ECasFree << endl;
	return 0;
}
