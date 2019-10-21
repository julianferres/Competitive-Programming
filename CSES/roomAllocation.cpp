#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define ii pair<int,int>
#define fore(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) for(int i=0; i<n; i++)
#define DBG(x) cerr << #x << " = " << (x) << endl

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> a;
	vector<pair<int,pair<int,int>>> rooms;
	forn(i,n){
		int s,e; cin >> s >> e;
		a.pb(mp(s,0)); a.pb(mp(e,1)); //0:"(" y 1:")"
		rooms.pb(mp(s,mp(0,i))); rooms.pb(mp(e,mp(1,i)));
	}
	sort(a.begin(),a.end());
	int ans=0,act=0;
	for(auto x: a){
		if(x.S==0) act+=1;
		else act-=1;
		ans = max(ans,act);
	}
	int alloc[n];
	set<int> available;
	fore(i,1,ans+1) available.insert(i);
	sort(rooms.begin(), rooms.end());
	for(auto x: rooms){
		if(x.S.F==0){ //Abro intervalo
			alloc[x.S.S] = *available.begin();
			available.erase(available.begin());
		}
		else available.insert(alloc[x.S.S]);
	}
	cout << ans << endl;
	forn(i,n) cout << alloc[i] << " ";
	cout << endl;
	return 0;
}