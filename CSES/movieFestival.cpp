#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

int main()
{
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  
	int n,s,e; vector< pair<int,int> > a;
	cin >> n;
	forn(i,n){
		cin >> s >> e;
		a.pb(mp(e,s));
	}
	sort(a.begin(), a.end());

	int ans,actEnd; ans = 0; actEnd = 0;

	forn(i,n){
		e = a[i].F; s = a[i].S;
		if(s>=actEnd){
			ans+=1;
			actEnd=e;
		}

	}
	cout << ans << endl;

	return 0;
}