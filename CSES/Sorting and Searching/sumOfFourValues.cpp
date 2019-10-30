#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef tuple<ll,ll,ll> iii;
typedef vector<iii> viii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

int main(){ 
    FIN;
    int n,x;
    cin >> n >> x;
    vi a(n); viii b;
    forn(i,n) cin >> a[i];
    forn(i,n-1)
        fore(j,i+1,n)
            b.emplace_back(a[i]+a[j],i+1,j+1);
    sort(b.begin(), b.end());
    forn(i,b.size()-1){
        int k = get<0>(b[i]);
        if(k>x/2) break;
        auto it = lower_bound(&b[i+1],&b[b.size()],make_tuple(x-k,0,0));
        while(k+get<0>(*it)==x){
            int p,q,r,x,y,z;
            tie(x,y,z) = b[i];
            tie(p,q,r) = *it;
            if(y==q || y==r || z==q || z==r){
                it++;continue;
            }
            cout << y << " " << z << " ";
            cout << q << " " << r << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}