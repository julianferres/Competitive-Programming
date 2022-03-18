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

int calculateMex(bool s[]){ 
    int mex = 0;   
    while(s[mex]) mex++; 
    return mex; 
} 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k; 
	cin >> n >> k;
	int p[k]; int g[n+1];
	g[0]=0;

	forn(i,k) cin >> p[i];

	fore(i,1,n+1){
		bool s[k+1] = {false};
		forn(j,k) if(i-p[j]>=0) s[g[i-p[j]]]=true;
		g[i] = calculateMex(s);
	}
	fore(i,1,n+1) cout << (g[i] ? "W" : "L");
	cout << endl;

	return 0;
}
