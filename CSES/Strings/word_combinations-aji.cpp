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
#define MOD 1000000000+7
#define esta(x,c) ((c).find(x) != (c).end())

namespace AhoCorasick
{
    typedef char Character;
    struct TrieNode
    {
        TrieNode() : wordIndex(-1) {}
        
        map<Character, TrieNode> children;
        int wordIndex;
        TrieNode *nextDictNode;
        TrieNode *nextTrieNode;
    };
    
    struct Trie
    {
        Trie() {}
        Trie(const vector<string> &v)
        {
            forn(i,v.size())
            {
                TrieNode *current = &root;
                forn(j, v[i].size())
                    current = &current->children[v[i][j]];
                current->wordIndex = i;
            }
            struct Event
            {
                Event(TrieNode *newCurrent, TrieNode *newParent, char newC) : current(newCurrent), parent(newParent), c(newC) {}
                TrieNode *current, *parent;
                Character c;
            };
            root.nextDictNode = root.nextTrieNode = NULL;
            queue<Event> q;
            q.push(Event(&root, NULL, 0));
            while (!q.empty())
            {
                TrieNode *current = q.front().current;
                TrieNode *parent  = q.front().parent;
                char c = q.front().c;
                q.pop();
                if (parent)
                {
                    current->nextTrieNode = automataTransition(parent->nextTrieNode, c);
                    current->nextDictNode = ( (current->nextTrieNode->wordIndex >= 0) ? 
                                                    current->nextTrieNode : 
                                                    current->nextTrieNode->nextDictNode
                                            );
                }
                for (auto &it : current->children)
                    q.push(Event(&it.second, current, it.first));
            }
        }
        
        TrieNode *automataTransition(TrieNode *currentState, Character x)
        {
            while (currentState && !esta(x, currentState->children)) currentState = currentState->nextTrieNode;
            return currentState ? &currentState->children[x] : &root;
        }
        
        vii reportAllMatches(const string &s)
        {
            vii pairsOfReports;
            TrieNode *currentState = &root;
            if (currentState->wordIndex >= 0) pairsOfReports.pb(mp(0,currentState->wordIndex)); // Por si esta la palabra vacia... (medio hijoeputa)
            forn(i,s.size())
            {
                TrieNode* matchingState = currentState = automataTransition(currentState, s[i]);
                if (matchingState->wordIndex < 0) matchingState = matchingState->nextDictNode;
                while (matchingState)
                {
                    pairsOfReports.pb(mp(i+1,matchingState->wordIndex));
                    matchingState = matchingState->nextDictNode;
                }
            }
            return pairsOfReports; 
        }
        
        TrieNode root;
    };
};


int main(){ 
    FIN;
    string text; cin >> text;
    int nn = text.size();
    ll n; cin >> n;
    vector<string> words;
    vector<int> len;

    forn(i,n){ 
        string s; cin >> s;
        len.pb(s.size());
        words.pb(s);
    }

    AhoCorasick::Trie t(words);
    vii pairsOfReports = t.reportAllMatches(text);
    
    vi occurences[nn];
    for(auto p: pairsOfReports){
        ll x = p.F, y =p.S;
        occurences[x-len[y]].pb(y);
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