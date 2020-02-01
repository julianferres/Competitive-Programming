/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
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
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 1005
#define INF 1e18

int n, m, q, t[4 * MAXN][4 * MAXN];
int a[MAXN + 5][MAXN + 5];
void build_y(int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry)
    {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    }
    else
    {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}
void build_x(int vx, int lx, int rx)
{
    if (lx != rx)
    {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
}
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (ly > ry)
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)) + sum_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}
int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m - 1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry) + sum_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val)
{
    if (ly == ry)
    {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    }
    else
    {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}
void update_x(int vx, int lx, int rx, int x, int y, int new_val)
{
    if (lx != rx)
    {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx * 2, lx, mx, x, y, new_val);
        else
            update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
}

int main()
{
    FIN;
    cin >> n >> q;
    m = n;
    forn(i, n)
    {
        forn(j, n)
        {
            char x;
            cin >> x;
            a[i][j] = (x == '*') ? 1 : 0;
        }
    }

    build_x(1, 0, n - 1);

    forn(i, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int y, x;
            cin >> y >> x;
            x--, y--;
            update_x(1, 0, n - 1, y, x, 1 - a[y][x]);
            a[y][x] = 1 - a[y][x];
        }
        else
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            y1--, y2--, x1--, x2--;
            cout << sum_x(1, 0, n - 1, y1, y2, x1, x2) << endl;
        }
    }
    return 0;
}
