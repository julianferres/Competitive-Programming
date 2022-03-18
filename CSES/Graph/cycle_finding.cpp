/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
typedef tuple<ll,ll,ll> e;
typedef vector<e> ve;
const ll INF = 100000000000000LL;

int main()
{
    FIN;
    int n,m; 
    cin >> n >> m;
    ve e(m);
    forn(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        e[i] = make_tuple(a-1,b-1,c);
    }
    vi d(n), p(n);
    int x;
    forn(i,n){
        x = -1;
        for(auto z:e){
            ll a, b, c;
            tie(a,b,c) = z;
            if(d[a]+c < d[b]){
                d[b] = d[a]+c;
                p[b] = a;
                x = b;
            }
        }
    }
    if(x == -1) cout << "NO\n";
    else{
        forn(i,n) x = p[x];
        int o = x;
        vi a(1,o);
        do{
            x = p[x];
            a.pb(x);
        }
        while(x!=o);
    reverse(a.begin(), a.end());
    cout << "YES\n";
    forn(i,a.size()){
        cout << a[i]+1;
        if(i < a.size()-1) cout << " ";
    }
    cout << endl;
    }
    return 0;
}

