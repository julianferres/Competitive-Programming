/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define esta(x, c) ((c).find(x) != (c).end())

set<string> seen;
vector<int> edges;
char lang[2] = {'0', '1'};

void go(string node)
{
    forn(i, 2)
    {
        string str = node + lang[i];
        if (!esta(str, seen))
        {
            seen.insert(str);
            go(str.substr(1));
            edges.pb(i);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string start = string(n - 1, lang[0]);
    go(start);
    string ans;
    forn(i, 1 << n)
        ans += lang[edges[i]];
    ans += start;

    cout << ans << endl;
    return 0;
}
