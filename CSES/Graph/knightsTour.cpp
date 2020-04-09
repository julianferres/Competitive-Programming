/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
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
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int visited[10][10];

int availableMoves(int x, int y)
{
    int ans = 0;
    forn(i, 8)
    {
        int newx = x + dx[i], newy = y + dy[i];
        if (newx < 0 || newx > 7 || newy < 0 || newy > 7)
            continue;
        ans += !visited[newy][newx];
    }
    return ans;
}

int main()
{
    FIN;
    int x, y;
    cin >> x >> y;
    x--, y--;
    visited[y][x] = 1;
    int i = 1;
    while (i < 64)
    {
        int nextx = -1, nexty = -1, minNextMoves = 8;
        forn(i, 8)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx < 0 || newx > 7 || newy < 0 || newy > 7 || visited[newy][newx])
                continue;
            else if (availableMoves(newx, newy) <= minNextMoves)
                nextx = newx, nexty = newy, minNextMoves = availableMoves(newx, newy);
        }

        x = nextx, y = nexty;
        i++;
        visited[y][x] = i;
    }

    forn(i, 8)
    {
        forn(j, 8)
                cout
            << visited[i][j] << " ";
        cout << endl;
    }

    return 0;
}
