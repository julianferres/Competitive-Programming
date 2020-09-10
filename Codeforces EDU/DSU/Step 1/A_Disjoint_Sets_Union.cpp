/*    AUTHOR: julianferres, Wed 09 Sep 2020 08:51:58 PM -03 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

int par[MAXN];
int find(int x){return par[x]=par[x]==x?x:find(par[x]);}
void join(int x, int y){par[find(x)]=find(y);}


int main(){  
    FIN;
    int n, m; cin >> n >> m;
    forn(i, n) par[i] = i;
    forn(i, m){
        string type; cin >> type;
        int u, v; cin >> u >> v;
        u--, v--;
        if(type == "union"){
            join(u, v);
        } else {
            cout << ((find(u) == find(v)) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
