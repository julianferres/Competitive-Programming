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
#define MAXN 100005
#define INF 1e18

const int
    MAXN = 200005,
    MAXLGN = 18;

int N, Q;
map<int, int> pos;
int tree[MAXN];
int cant;
struct node
{
    int val, L, R, size;
} buff[2 * MAXN * MAXLGN];

int build(int lo, int hi)
{
    if (lo > hi)
        return 0;

    int idx = ++cant;

    int mid = (lo + hi) / 2;
    buff[idx] = (node){mid, build(lo, mid - 1), build(mid + 1, hi), 0};
    return idx;
}

int update(int x, int val, int amount)
{

    if (x == 0)
        return 0;

    int idx = ++cant;

    int L = buff[x].L;
    int R = buff[x].R;
    if (val < buff[x].val)
        L = update(L, val, amount);
    if (val > buff[x].val)
        R = update(R, val, amount);

    buff[idx] = (node){buff[x].val, L, R, buff[x].size + amount};

    return idx;
}

int query(int x, int val)
{
    if (val < buff[x].val)
        return query(buff[x].L, val) + buff[x].size - buff[buff[x].L].size;

    if (val > buff[x].val)
        return query(buff[x].R, val);

    return buff[x].size - buff[buff[x].L].size;
}

int main()
{

    scanf("%d", &N);

    tree[0] = build(1, N);
    for (int i = 1; i <= N; i++)
    {
        int x, posx;
        cin >> x;
        posx = pos[x];
        if (posx != 0)
            tree[i] = update(update(tree[i - 1], posx, -1), i, +1);
        else
            tree[i] = update(tree[i - 1], i, +1);
        pos[x] = i;
    }

    scanf("%d", &Q);
    while (Q--)
    {
        int lo, hi;
        scanf("%d %d", &lo, &hi);
        printf("%d\n", query(tree[hi], lo));
    }

    return 0;
}