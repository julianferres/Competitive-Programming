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

const int N = 22;
const int mod = 1e9+7;
vector<vi> can(N, vi(N,0));
int n; vi dp(1<<N,0); //girls matched

void add(ll &a, ll b){
	a+= b;
	if(a>=mod) a-= mod;
}

int main()
{
	FIN;
	cin >> n;
	forn(i,n) forn(j,n) cin >> can[i][j];
	dp[0] = 1;
	forn(mask,1<<n){
		ll i = __builtin_popcount(mask);
		forn(j, n)
		{
			if(can[i][j] && !((1<<j) & mask))
				add(dp[(1<<j)^mask],dp[mask]);
		}
	}
	cout << dp[(1<<n)-1] << endl;

    return 0;
}
