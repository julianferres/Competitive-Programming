#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define fore(i,a,b) for(ll i=a; i<b; i++)

void calcsubarray(ll a[], ll x[], int n, int c){
	forn(i,1<<n){
		ll s = 0;
		forn(j,n){
			if(i&(1<<j)) s+= a[j+c];
		}
		x[i]=s;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,S; cin >> n >> S;
	ll X[1050000], Y[1050000];
	
	ll a[n]; forn(i,n) cin >> a[i];

	calcsubarray(a,X,n/2,0);
	calcsubarray(a,Y,n-n/2,n/2);
	int sX = 1 <<(n/2), sY= 1 <<(n-n/2);
	ll ans = 0;
	forn(i,sX){
		if(S-i<sY) ans+=X[i]*Y[S-i];
	}


	return 0;
}
