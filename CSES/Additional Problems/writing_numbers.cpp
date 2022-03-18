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
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

ll ones(ll n){
    ll ones = 0, m = 1;
    while(m <= n){
        ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        m *= 10;
    }
    // DBG(ones);
    return ones;
}

int main(){
    FIN;
    ll n;
    cin >> n;
    ll l = 0, r = (1 << 30);
    ll ans = r;
    ll mid;
    while (l <= r)
    {
        mid = l + (r - l)/2;
        if(ones(mid)>n){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans - 1 << endl;

    // La cuenta hasta n de 1's de
    // n=10->1
    // n=100->20
    // n=1000->300     es log_10(n)*n//10
    // n=10000->4000
    // n=100000->50000
    // n=1000000->600000

    return 0;
}
