#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0; i<n; i++)
#define fore(i,a,b) for(int i=a; i<b; i++)

int tri(int n){
	return n*(n+1)/2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	double pInv[n][n]={0};
	int r[n]; forn(i,n) cin >> r[i];

	forn(i,n){
		fore(j,i+1,n){
			if(r[i]<=r[j]) pInv[i][j] = ((double)tri(r[i]-1))/(r[i]*r[j]);
			else pInv[i][j] = ((double)(tri(r[j])+r[j]*(r[i]-1-r[j])))/(r[i]*r[j]);
		}
	}
	double ans = 0;
	forn(i,n) forn(j,n) ans+=pInv[i][j];
	cout << setprecision(6) << fixed << ans << endl;	

	return 0;
}
