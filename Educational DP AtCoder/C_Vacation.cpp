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

    ll n;
    cin >> n;
    vector<vi> dp(n + 1, vi(3,0));

    ll a, b, c;
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    forr(i,1,n){
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c;
    }
    cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;

    return 0;
}

