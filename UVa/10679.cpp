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


struct state
{
    int len,link;
    map<char,int> next;
};

const int MAXLEN = 100005;
state st[MAXLEN*2];
int sz, last;

void sa_init(){
    st[0].len = 0;
    st[0].link = -1;
    st[0].next.clear();
    sz = 0;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].next.clear();
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void solve(string S, int q){
    sa_init();
    forn(i,S.size()) sa_extend(S[i]);
    forn(j,q){
        string T; cin >> T;
        int nodoAct = 0;
        bool flag = true;
        for(char t: T){
            if(!esta(t,st[nodoAct].next)){
                flag = false;
                break;
            }
            nodoAct = st[nodoAct].next[t];
        }
        char x = flag  ? 'y' : 'n';
        cout << x << endl;    
    }
}

int main()
{
    FIN;
    int k; cin >> k;
    forn(i,k){
        string S; cin >> S;
        int q; cin >> q;
        solve(S,q);        
    }
    return 0;
}