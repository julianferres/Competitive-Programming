#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define inf 2000000
#define MAXINT 1000005
int memo[MAXINT];
int recursion = 0;
int rec(int n){
	if(n==0) return memo[0] = 0;
	if(n<10) return memo[n]=1;
	if(memo[n]!=-1) return memo[n];
	string s = to_string(n);
	int m = inf;
	forn(i,s.sz){
		if(s[i]-'0'>0){
			recursion++;
			m = min(m,1+rec(n-(s[i]-'0')));
		}
	}
	return memo[n] = m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
  	
  	int n; cin >> n;
  	forn(i,n+1) memo[i]=-1;
  	forn(i,n+1) rec(n);
  	cout << memo[n] << endl;
	return 0;
}
