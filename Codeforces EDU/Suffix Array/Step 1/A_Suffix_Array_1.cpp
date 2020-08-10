/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
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
#define show(v, n)                  \
    cerr << #v << " = ";            \
    forn(i, n) cerr << v[i] << " "; \
    cerr << endl;
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll inf = 1LL << 62;
const int mod = 1e9 + 7; // 998244353
const int MAXN = 2e5 + 5;

pair<int, int> sf[MAXN];
bool sacomp(int lhs, int rhs) { return sf[lhs] < sf[rhs]; }
vector<int> constructSA(string &s)
{                     // O(n log^2(n))
    int n = s.size(); // (sometimes fast enough)
    vector<int> sa(n), r(n);
    forr(i, 0, n) r[i] = s[i];
    for (int m = 1; m < n; m *= 2)
    {
        forr(i, 0, n) sa[i] = i, sf[i] = mp(r[i], i + m < n ? r[i + m] : -1);
        stable_sort(sa.begin(), sa.end(), sacomp);
        r[sa[0]] = 0;
        forr(i, 1, n) r[sa[i]] = sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i - 1]];
    }
    return sa;
}

int main()
{
    FIN;
    string s; cin >> s;
    vector<int> ans = constructSA(s);
    cout << s.size() << " ";
    forn(i,ans.size()) cout << ans[i] << " ";
    cout << endl;

    return 0;
}