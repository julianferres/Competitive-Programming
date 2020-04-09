#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MAXN 200005

int main()
{
    FIN;
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> m;
    set<ii> intervalos; // Izq, long
    int c_act = 1;
    char b = s[0];
    forr(i, 1, n)
    {
        if (s[i] == b)
            c_act++;
        else
        {
            m[i - c] = c;
            interalos.insert({c, i - c});
            b = s[i];
            c_act = 1;
        }
    }
    m[n - c] = c;
    a.insert({c, n - c});

    
    return 0;
}
