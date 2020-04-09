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
const int N = 3005;

vector<vi> dp(N, vi(N,-1));
int n;
vi a(N);

ll fill(int l, int r){
    if(dp[l][r]!=-1) return dp[l][r];

    if(l > r)
        return dp[l][r] = 0;
    if (l == r)
        return dp[l][r] = a[l];
    if(l+1 == r)
        return dp[l][r] = max(a[l] - a[r], a[r] - a[l]);

    ll ansll = fill(l + 2, r) + a[l] - a[l + 1];
    ll anslr = fill(l + 1, r - 1) + a[l] - a[r];
    ll ansrl = fill(l + 1, r - 1) + a[r] - a[l];
    ll ansrr = fill(l, r - 2) + a[r] - a[r - 1];

    return dp[l][r] = max(min(ansll,anslr),min(ansrl,ansrr));
}

int main(){
    FIN;
    cin >> n;
    forn(i, n) cin >> a[i];

    fill(0, n - 1);
    cout << dp[0][n - 1] << endl;
    return 0;
}

