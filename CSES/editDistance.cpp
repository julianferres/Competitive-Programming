#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

ll editDistance(string s1, string s2, int m, int n){
	ll dp[m+5][n+5]; forn(i,m+1)forn(j,n+1) dp[i][j]=0LL;
	forn(i,m+1)
		forn(j,n+1){
			if(j==0 || i==0) dp[i][j] = i+j;
			else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
			else{
				dp[i][j] = 1;
				ll aux = min(dp[i][j-1],dp[i-1][j]);
				aux = min(aux,dp[i-1][j-1]);
				dp[i][j]+=aux;	
			} 
		}
	return dp[m][n];

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2; cin >> s1 >> s2;
	cout << editDistance(s1,s2,(int) s1.size(),(int)s2.size()) << endl;
	return 0;
}
/*



def editDistance(s1,s2,m,n):
	dp = [[0 for _ in range(n+1)] for __ in range(m+1)]

	for i in range(m+1):
		for j in range(n+1):
			if not i or not j: dp[i][j]=i+j
			elif(s1[i-1]==s2[j-1]):
				dp[i][j] = dp[i-1][j-1]
			else:
				dp[i][j] = 1+ min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])
	return dp[m][n]

s1 = input()
s2 = input()

print(editDistance(s1,s2,len(s1),len(s2)))*/
