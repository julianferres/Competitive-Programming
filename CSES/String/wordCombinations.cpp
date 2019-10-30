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
#define RAYA cerr << "===============================" << endl
#define MODD 1000000000+7

struct Hash {
    int P=1777771,MOD[2],PI[2];
    vector<int> h[2],pi[2];
    Hash(string& s){
        MOD[0]=999727999;MOD[1]=1070777777;
        PI[0]=325255434;PI[1]=10018302;
        fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
        fore(k,0,2){
            h[k][0]=0;pi[k][0]=1;
            ll p=1;
            fore(i,1,s.size()+1){
                h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
                pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
                p=(p*P)%MOD[k];
            }
        }
    }
    ll get(int s, int e){
        ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
        h0=(1LL*h0*pi[0][s])%MOD[0];
        ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
        h1=(1LL*h1*pi[1][s])%MOD[1];
        return (h0<<32)|h1;
    }
};



int main(){ 
    FIN;
    string text; cin >> text;
    int nn = text.size();
    ll n; cin >> n;
    vector<int> len(n);
    vii hashPat;
    forn(i,n){ 
        string s; cin >> s;
        len[i]=s.size();
        struct Hash hashi= Hash(s);
        hashPat.pb(mp(hashi.get(0,len[i]),i));
    }   
    vi occurences[nn];
    sort(hashPat.begin(), hashPat.end());
    struct Hash hashText = Hash(text);
    forn(i,nn){
        fore(j,i+1,nn+1){
            ll hashij = hashText.get(i,j);

            auto it = lower_bound(hashPat.begin(), hashPat.end(),mp(hashij,0LL));
            if((*it).F==hashij)
                occurences[i].pb((*it).S);
        }
    }

    ll dp[nn];
    forn(i,nn) dp[i]=0;
    for(int i = nn-1; i>=0; i--){
        for(auto id: occurences[i]){
            if(len[id]+i==nn) dp[i]+=1;
            if(len[id]+i<nn) dp[i]+= dp[i+len[id]];
            dp[i]%=MODD;
        }
        dp[i]%=MODD;
    }
    /*forn(i,nn){
        cout << dp[i] << " ";
    }
    cout << endl;
    */
    cout << dp[0] << endl;
    return 0;
}