#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
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

int find(vi &l, int x){
    while(x!=l[x]) x = l[x];
    return x;
}

void u(vi &l , vi &s, int a, int b){
    a = find(l,a), b = find(l,b);
    if(a==b) return;
    if(s[a]<s[b]) swap(a,b);
    s[a]+=s[b];
    l[b] = a;
}



int main(){ 
    FIN;
    int n,m; cin >> n >> m;
    vi l(n*m,-1), s(n*m,1);
    vvb a(n);
    forn(i,n){
        a[i]=vb(m,false);
        forn(j,m){
            char b; cin >> b;
            if(b=='.') a[i][j]=true;
            l[i*m+j] = i*m+j;
        }
    }
    forn(i,n)
        forn(j,m){
            if(j<m-1 && a[i][j] && a[i][j+1])
                u(l,s,i*m+j,i*m+j+1);
            if(i<n-1 && a[i][j] && a[i+1][j])
                u(l,s,i*m+j,(i+1)*m+j);
        }
    
    si r; //Cuento la cantiad de padres diferentes
    forn(i,n) forn(j,m) if(a[i][j]) r.insert(find(l,i*m+j));

    cout << r.size() << endl;
    return 0;
}