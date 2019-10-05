#include <bits/stdc++.h>
using namespace std;

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

int main(){

  	ios::sync_with_stdio(0);
  	cin.tie(0);
	int n; cin >> n;
	int s,e; vector< pair<int,int> > v;

	forn(i,n){
		cin >> s >> e;
		v.push_back(make_pair(s,1));
		v.push_back(make_pair(e,-1));
	}
	sort(v.begin(),v.end());
	int ans = 0;
	int act = 0;
	forn(i,2*n){
		act+= v[i].S;
		ans = max(ans, act);
	}		

	cout << ans << endl;
	return 0;
}