#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

vii pruefer_decode(vi code){
	int n = code.size()+2;
	vi degree(n,1);
	for(int i: code) degree[i]++;
	set<int> leaves;
	forn(i,n){
		if(degree[i]==1) leaves.insert(i);
	}
	vii edges;
	for(int v: code){
		int leaf = *leaves.begin();
		leaves.erase(leaves.begin());

		edges.emplace_back(min(leaf,v),max(leaf,v));
		if(--degree[v]==1) leaves.insert(v);

	}
		edges.emplace_back(*leaves.begin(),n-1);
		return edges;
}

int main(){ 
	FIN;
	ll n; cin >> n;
	vi code(n-2);
	forn(i,n-2){cin >> code[i]; code[i]--;}
	vii ans = pruefer_decode(code);
	forn(i,ans.size()) cout << ans[i].F+1 << " " << ans[i].S+1 << endl;
	return 0;
}