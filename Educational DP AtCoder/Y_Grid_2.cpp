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
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int inf = 1<<30; // const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 2e5+5;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a,ll m){return binpow(a, m-2, m);}

ll factorial[1000005];
void init_factorial(){
    factorial[0] = 1;
    forr(i,1,1000003) //Usually 10**6+5 is a good choice
        factorial[i] = factorial[i-1] * i % mod;
}
ll nck(ll n, ll k){
    return factorial[n] * modinv(factorial[k], mod) % mod * modinv(factorial[n - k], mod) % mod;
}


bool cmp(ii a, ii b){
    ll xa=a.first,ya=a.second,xb=b.first,yb=b.second;
    if(ya<=yb&&xa<=xb) return true;
    if (ya>=yb&&xa>=xb) return false;
    return ya<=yb;
}

void add(ll &a, ll b){
    a += b;
    if(a>=mod)
        a -= mod;
}

int main()
{
    FIN;
    init_factorial();

    ll h,w,n, x, y;
    cin >> h >> w >> n;
    ii z[n]; ll c[n];
    forn(i,n){
        cin >> y >> x;
        z[i] = {y, x};
    }
    sort(z,z+n,cmp); //Los anteriores molestan al actual
    ll ans = nck(h+w-2, h-1);

    forn(i,n){
        y=z[i].first,x=z[i].second;
        c[i] = nck(x+y-2,x-1);
        forn(j,i){
            ll a=z[j].first,b=z[j].second;
            if(a>y || b>x) continue;
            c[i] = (c[i] - c[j]*nck(y-a+x-b,x-b)%mod)%mod;
        }
        ans = (ans-c[i]*nck(h+w-x-y,w-x)%mod)%mod;
        ans = (ans+mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
