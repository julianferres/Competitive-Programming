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
const int mod = 1e9+7; // 998244353
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MAXN  = 2e5+5;

typedef vector<vector<unsigned int>> Matrix;
Matrix ones(ll n) {
    Matrix r(n,vector<unsigned int>(n));
    forr(i,0,n)r[i][i]=1;
    return r;
}

Matrix operator*(Matrix &a, Matrix &b) {
    int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
    Matrix r(n,vector<unsigned int>(m));
    forr(i,0,n)forr(j,0,m)forr(k,0,z)
        r[i][j]+=a[i][k]*b[k][j];
    return r;
}
Matrix be(Matrix b, ll e) {
    Matrix r=ones(SZ(b));
    while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
    return r;
}

bool valido(int r, int c){
	return min(r,c)>=0 && max(r,c)<=7;
}

int main() {
    FIN;

	int k; cin >> k;
	Matrix t(65, vector<unsigned int>(65));
	
	forn(i,8)
		forn(j,8)
			for(int dr: {-2,-1,1,2})
				for(int dc: {-2,-1,1,2})
					if(abs(dr)!=abs(dc))
						if(valido(i+dr,j+dc))
							t[8*i+j][8*(i+dr)+(j+dc)] = 1;
	
	
	forn(i,65) t[i][64] = 1;
	
	Matrix ans = be(t,k+1);
	
	cout << ans[0][64] << endl;


	return 0;
}	


