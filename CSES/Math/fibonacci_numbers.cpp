#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define MOD 1000000007
void multiply(ll F[2][2], ll M[2][2]) 
{ 
  ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD; 
  ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD; 
  ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD; 
  ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

void power(ll F[2][2], ll n) 
{ 
  ll res[2][2] = {{1LL,0LL},{0LL,1LL}};
  while(n>0){
		if(n&1) multiply(res,F);
		multiply(F,F);
		n >>= 1;
	}
	multiply(F,res);
}

ll fib(ll n){
	ll F[2][2] = {{1LL,1LL},{1LL,0LL}};
	if(n==0) return 0;
	power(F,n-2);
	return F[0][0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n; cin >> n;
	ll ans = fib(n);
	cout << ans << endl;
	return 0;
}
