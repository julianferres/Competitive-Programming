/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
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
#define MAXN 100005

set<ii> s;
vector<ii> ans;

int main()
{
    FIN;
    int n;
    cin >> n;
    forn(i, n)
    {
        int x;
        cin >> x;
        s.insert(mp(x, i + 1));
    }
    forn(i, n)
    {
        int actd = s.rbegin()->first;
        int acti = s.rbegin()->second;
        if (!actd)
            break;
        s.erase(--s.end());

        vector<ii> aux;
        forn(ii, actd)
        {
            int lastd = s.rbegin()->first;
            int lasti = s.rbegin()->second;
            s.erase(--s.end());
            if (!lastd)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            aux.pb(mp(lastd - 1, lasti));
            ans.pb(mp(acti, lasti));
        }
        forn(i, aux.size()) s.insert(aux[i]);
        s.insert(mp(0, acti));
    }
    cout << ans.size() << endl;
    forn(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
