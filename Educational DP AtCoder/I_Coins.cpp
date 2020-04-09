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

int main(){
    FIN;
    int n;
    cin >> n;
    vector<double> p(n, 0);
    forn(i, n) cin >> p[i];

    vector<double> dp(n + 1, 0);

    dp[1] = p[0];
    dp[0] = 1 - p[0];
    double aux = 0, aux1 = 0;
    forr(i, 1, n)
    {
        dp[0] *= (1 - p[i]);
        aux = dp[0];
        forr(j, 1, n + 1) if (j <= i + 1)
        {
            aux1 = dp[j];
            dp[j] = aux * p[i] + dp[j] * (1 - p[i]);
            aux = aux1;
        }
    }
    double sum = 0;
    forn(i, n + 1) if (i > n - i) sum += dp[i];
    cout << fixed << setprecision(12) << sum << endl;
    

    return 0;
}

