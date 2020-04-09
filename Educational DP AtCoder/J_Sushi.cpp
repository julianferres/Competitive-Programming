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
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 1000000007
const int N = 305;

double dp[N][N][N];
int n;

double fill(int a,int b, int c){
	// DBG(a);
	// DBG(b);
	// DBG(c);
	if (dp[a][b][c] > -0.5)
		return dp[a][b][c];
	// DBG(a);
	// DBG(b);
	// DBG(c);

	int z = n-(a+b+c);
	int nz = (a+b+c);
	double aux1=0,aux2=0,aux3=0;

	if(a)
		aux1 = (double) a/(a+b+c)*fill(a-1, b, c);
	if(b)
		aux2 = (double) b/(a+b+c)*fill(a+1, b-1, c);
	if(c)
		aux3 = (double) c/(a+b+c)*fill(a, b+1, c-1);

	double ans = (double) nz/n*(aux1+aux2+aux3+1) + (double)z/n;
	ans *= (double)n/nz;
	return dp[a][b][c] = ans;
}


int main(){
    FIN;
    cin >> n;
    vi a(n);
    int c[4] = {0,0,0,0};
    forn(i,n){
    	int x; cin >> x;
    	++c[x];
    }
	forn(i, N) forn(j, N) forn(k, N) dp[i][j][k] = -1;
	dp[0][0][0] = 0;

	fill(c[1],c[2],c[3]);
	// DBG(dp[0][0][0]);
	// DBG(dp[1][0][0]);
	// DBG(dp[2][0][0]);
	// DBG(dp[3][0][0]);
	cout << fixed << setprecision(15) << dp[c[1]][c[2]][c[3]] << endl;

	return 0;
}

