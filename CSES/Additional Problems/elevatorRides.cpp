/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define mp make_pair
#define N 20

pair<int, int> best[1 << N];

int main()
{
    FIN;
    int n, x;
    cin >> n >> x;
    ll weight[n + 5];
    forn(i, n) cin >> weight[i];
    best[0] = {1, 0};
    forr(s, 1, (1 << n))
    {
        best[s] = {n + 1, 0};
        forn(p, n)
        {
            if (s & (1 << p))
            {
                auto option = best[s ^ (1 << p)];
                if (option.second + weight[p] <= x)
                    option.second += weight[p];
                else
                {
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    cout << best[(1 << n) - 1].first << endl;
    return 0;
}
