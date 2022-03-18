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
#define MAXN 200005

ll x[MAXN], cnt[MAXN];
map<ll, ll> m;

ll block_size;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vi mo_s_algorithm(vector<Query> queries)
{
    vi answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = 0;
    int ans = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_r < q.r)
            if (++cnt[x[cur_r++]] == 1)
                ans++;
        while (cur_r > q.r)
            if (--cnt[x[--cur_r]] == 0)
                ans--;
        while (cur_l < q.l)
            if (--cnt[x[cur_l++]] == 0)
                ans--;
        while (cur_l > q.l)
            if (++cnt[x[--cur_l]] == 1)
                ans++;
        answers[q.idx] = ans;
    }
    return answers;
}

int main()
{
    FIN;
    ll n, q;
    cin >> n >> q;
    vector<Query> queries(q);
    block_size = (ll)sqrt(n + .0) + 1;

    forn(i, n)
    {
        int y;
        cin >> y;
        if (esta(y, m))
            x[i] = m[y]; //Compresion
        else
            x[i] = m.size(), m[y] = x[i]; //Le asigno el siguiente color comprimido
    }
    forn(i, q)
    {
        ll a, b;
        cin >> a >> b;
        queries[i].l = a - 1, queries[i].r = b, queries[i].idx = i;
    }

    vi answers = mo_s_algorithm(queries);

    forn(i, q) cout << answers[i] << endl;
    return 0;
}