/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
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
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define MAXN 100005

ll parent[MAXN],size[MAXN];
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}


int main()
{
    FIN;
    ll n,m; cin >> n >> m;
    forn(i,n) make_set(i);
    ll act_max_size = 1;
    ll n_groups = n;
    forn(i,m){
        ll a,b; cin >> a >> b; a--,b--;
        if(find_set(a)!=find_set(b))
            n_groups--;
        union_sets(a,b);

        act_max_size = max(act_max_size,max(size[parent[a]],size[parent[b]]));

        cout << n_groups << " " << act_max_size << endl;
    }

    return 0;
}


