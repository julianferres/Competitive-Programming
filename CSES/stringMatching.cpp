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

vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.sz+1);r[0]=-1;
	int j = -1;
	fore(i,0,t.sz){
		while(j>=0&&t[i]!=t[j]) j=r[j];
		r[i+1]=++j;
	}
	return r;
}
int kmp(string& s, string& t){
	int ans=0;
	int j=0; vector<int> b=kmppre(t);
	fore(i,0,s.sz){
		while(j>=0&&s[i]!=t[j]) j=b[j];
		if(++j==t.sz) ans++,j=b[j];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s,t; cin >> s >> t;
	int ans = kmp(s,t);
	cout << ans << endl;
	return 0;
}
