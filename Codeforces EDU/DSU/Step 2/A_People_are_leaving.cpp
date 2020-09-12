#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MAXN = 1000000+5;

vector <int> link(MAXN), sz(MAXN);
void iniciar(int n) { forn(i,n+1) link[i]=i, sz[i] = 1; }
int find(int x){return link[x]=link[x]==x?x:find(link[x]);}
void join(int a, int b) {
	a=find(a); b=find(b);
	if(a < b) swap(a,b);
	sz[a]+=sz[b];
	link[b]=a;
}

int main(){  

    FIN;

    int n, m; cin >> n >> m;
    iniciar(n+1);
    
    forn(i, m){
        char t; cin >> t;
        int x; cin >> x; x--;
        if(t=='-'){
            join(x, x+1);
        } else {
            int par_x = find(x);
            cout << (par_x == n ? -1 : par_x + 1 )<< "\n";
        }
    }

    return 0;
}
