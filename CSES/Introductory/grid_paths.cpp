/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define DBG(x) cerr << #x << " = " << (x) << endl

string s;
bool g[7][7]; //Visitados

int rec(int y, int x, int i, char m)
{
    if (i == 48)
        return 1; //Backtracking OK
    if (g[6][0])
        return 0;
    if (m == 'L' && (x == 0 || g[y][x - 1]) && y > 0 && y < 6 && !g[y - 1][x] && !g[y + 1][x])
        return 0;
    if (m == 'R' && (x == 6 || g[y][x + 1]) && y > 0 && y < 6 && !g[y - 1][x] && !g[y + 1][x])
        return 0;
    if (m == 'U' && (y == 0 || g[y - 1][x]) && x > 0 && x < 6 && !g[y][x - 1] && !g[y][x + 1])
        return 0;
    if (m == 'D' && (y == 6 || g[y + 1][x]) && x > 0 && x < 6 && !g[y][x - 1] && !g[y][x + 1])
        return 0;
    if (s[i] == '?')
    {
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, -1, 0, 1};
        int k = 0;
        forn(j, 4)
        {
            int ynew = y + dy[j];
            int xnew = x + dx[j];
            if (xnew < 0 || xnew > 6)
                continue;
            if (ynew < 0 || ynew > 6)
                continue;
            if (g[ynew][xnew])
                continue;
            g[ynew][xnew] = true;
            k += rec(ynew, xnew, i + 1, "ULDR"[j]);
            g[ynew][xnew] = false;
        }
        return k;
    }

    if (s[i] == 'L')
        x--;
    else if (s[i] == 'R')
        x++;
    else if (s[i] == 'U')
        y--;
    else if (s[i] == 'D')
        y++;
    if (x < 0 || x > 6)
        return 0;
    if (y < 0 || y > 6)
        return 0;
    if (g[y][x])
        return 0;
    g[y][x] = true;
    int k = rec(y, x, i + 1, s[i]);
    g[y][x] = false; //Backtrack
    return k;
}
int main()
{
    FIN;
    cin >> s;
    g[0][0] = true;
    cout << rec(0, 0, 0, 0) << endl;
    return 0;
}
