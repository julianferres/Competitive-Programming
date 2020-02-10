/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ii, null_type, less_equal<ii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set_ii;
typedef vector<ll> vi;
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
#define MAXN 200005
#define INF 1e18
int n;

ll parte_1(ll a[])
{
    //1- Swappear dos adyacente (contar inversiones)
    indexed_set s;
    ll ans1 = 0;
    s.insert(a[0]);
    forr(i, 1, n)
    {
        ans1 += i - s.order_of_key(a[i]);
        s.insert(a[i]);
    }
    return ans1;
}

ll parte_2(ll a[])
{
    //2 - Swappear dos cualquiera
    indexed_set_ii sii;
    ll copy_a[MAXN];
    forn(i, n) copy_a[i] = a[i];
    forn(i, n) sii.insert(mp(copy_a[i], i));
    ll ans2 = 0, l = 0;
    forn(i, n)
    {
        ll value = sii.find_by_order(0)->first;
        ll pos = sii.find_by_order(0)->second;
        sii.erase(sii.find_by_order(0));
        if (copy_a[l] != value)
        {
            sii.erase(sii.find_by_order(sii.order_of_key(mp(copy_a[l], l))));
            sii.insert(mp(copy_a[l], pos));
            copy_a[pos] = copy_a[l];
            ans2++;
        }
        l++;
    }
    return ans2;
}

ll parte_3(ll a[])
{
    set<ll> ss;
    forn(i, n)
    {
        ll z = a[i];
        ss.insert(z);
        auto it = ss.find(z);
        it++;
        if (it != ss.end())
            ss.erase(it);
    }

    return n - ss.size();
}

ll parte_4(ll a[])
{
    //4- Mandar adelante
    ll k = n;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == k)
            k--;
    return k;
}

int main()
{
    FIN;
    cin >> n;
    ll a[n + 5];
    forn(i, n) cin >> a[i];

    ll ans1 = parte_1(a);
    ll ans2 = parte_2(a);
    ll ans3 = parte_3(a);
    ll ans4 = parte_4(a);

    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;

    return 0;
}
