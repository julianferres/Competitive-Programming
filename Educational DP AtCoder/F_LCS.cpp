/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005

int main(){
    FIN;
    string s, p;
    cin >> s >> p;
    ll n = s.size(), m = p.size();

    vector<vi> dp(n + 1, vi(m + 1, 0));

    forn(i,n+1){
        forn(j,m+1){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s[i-1]==p[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    ll r = n, c = m, toWrite = dp[n][m];
    char ans[dp[n][m]];

    while (r > 0 && c> 0)
    {
        if(s[r-1] == p[c-1]){
            ans[--toWrite] = s[r - 1];
            c--, r--;
        }
        else if(dp[r-1][c]>dp[r][c-1])
            r--;
        else
            c--;
    }
    forn(i,dp[n][m])
        cout << ans[i];
    cout << endl;

    return 0;
}

/*


i, j = n, m
ans = []

while i and j:
    if s[i - 1] == p[j - 1]:
        ans.append(s[i - 1])
        i -= 1
        j -= 1
    elif dp[i - 1][j] > dp[i][j - 1]:
        i -= 1
    else:
        j -= 1


ans.reverse()
print("".join(ans))
        
*/
    


