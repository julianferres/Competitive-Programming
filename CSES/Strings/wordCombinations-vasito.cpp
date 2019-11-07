#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define MOD 1000000000+7
#define esta(x,c) ((c).find(x) != (c).end())
 
struct vertex {
    map<char,int> next,go; 
    int p,link;
    char pch;
    vector<int> leaf;
    vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
    t.clear();t.pb(vertex());
}
void add_string(string s, int id){
    int v=0;
    for(char c:s){
        if(!t[v].next.count(c)){
            t[v].next[c]=t.size();
            t.pb(vertex(v,c));
        }
        v=t[v].next[c];
    }
    t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){
    if(t[v].link<0)
        if(!v||!t[v].p)t[v].link=0;
        else t[v].link=go(get_link(t[v].p),t[v].pch);
    return t[v].link;
}
int go(int v, char c){
    if(!t[v].go.count(c))
        if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
        else t[v].go[c]=v==0?0:go(get_link(v),c);
    return t[v].go[c];
}
 
 
 
int main(){ 
    FIN;
    string text; cin >> text;
    int nn = text.size();
    ll n; cin >> n;
    vector<string> words;
    vector<int> len;
    aho_init();
    vii pairsOfReports;
    forn(i,n){ 
        string s; cin >> s;
        len.pb(s.size());
        words.pb(s);
    }
 
    forn(i,n) add_string(words[i],i);
    int v = 0;
    forn(i,nn){
        char c = text[i];
        v = go(v,c);
        int aux = v;
        while(aux!=0){
            forn(j,t[aux].leaf.size()) pairsOfReports.pb(mp(i,t[aux].leaf[j]));
            aux = get_link(aux);
        }
    }
    vi occurences[nn];
    for(auto p: pairsOfReports){
        ll x = p.F, y =p.S;
        DBG(x); DBG(y);
    }
    for(auto p: pairsOfReports){
        ll x = p.F, y =p.S;
 
        occurences[x-len[y]+1].pb(y);
    }
 
    ll dp[nn];
    forn(i,nn) dp[i]=0;
    for(int i = nn-1; i>=0; i--){
        for(auto id: occurences[i]){
            if(len[id]+i==nn) dp[i]+=1;
            if(len[id]+i<nn) dp[i]+= dp[i+len[id]];
            dp[i]%=MOD;
        }
        dp[i]%=MOD;
    }
    cout << dp[0] << endl;
    return 0;
}