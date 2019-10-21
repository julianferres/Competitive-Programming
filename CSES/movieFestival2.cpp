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
  
	int n,s,e,k; set<pair<int,int>> a;
	cin >> n >> k;
	forn(i,n){
		cin >> s >> e;
		a.insert(mp(e,s));
	}
	int ans,actEnd; ans = 0;
	while(k-- && !a.empty()){
		actEnd = 0;
		for(auto x: a){
			e = x.F; s = x.S;
			if(s>=actEnd){
				ans+=1;
				actEnd=e;
			}
		}
	}
	cout << ans << endl;

	return 0;
}