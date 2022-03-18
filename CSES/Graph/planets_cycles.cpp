/******************************************
*    AUTHOR:         julianferres         *
******************************************/
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
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005

vi g(MAXN), d(MAXN, 0);

vi toCycle(MAXN, -1), lenCycle(MAXN, -1);

void go(int v)
{
    map<int, int> seen;
    seen[v] = 0;
    int i = 1;
    while (!esta(g[v], seen))
    {
        if (toCycle[v] != -1)
        {
            for (auto x : seen)
            {
                toCycle[x.first] = seen[v] - seen[x.first] + toCycle[v];
                lenCycle[x.first] = lenCycle[v];
            }
            return;
        }
        v = g[v];
        seen[v] = i;
        i++;
    }
    int cycleStart = g[v];
    int lenActCycle = i - seen[cycleStart];
    for (auto x : seen)
    {
        toCycle[x.first] = max(0, seen[cycleStart] - seen[x.first]);
        lenCycle[x.first] = lenActCycle;
    }
}

int main()
{
    FIN;
    int n;
    cin >> n;
    int n;
    forn(i, n)
    {
        int to;
        cin >> to, to--;
        if (to == i)
        {
            toCycle[i] = 0;
            lenCycle[i] = 1;
        }
        g[i] = to;
        d[i]++, d[to]++;
    }
    forn(nodo, n) if (d[nodo] == 1) go(nodo);
    forn(nodo, n) go(nodo);
    /*forn(i, n) cout << toCycle[i] << " \n"[i == n - 1];
    forn(i, n) cout << lenCycle[i] << " \n"[i == n - 1];*/

    forn(i, n) cout << toCycle[i] + lenCycle[i] << " \n"[i == n - 1];
    return 0;
}
