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

#define RB(x) (x < n ? r[x] : 0)
void csort(vector<int> &sa, vector<int> &r, int k)
{
    int n = sa.size();
    vector<int> f(max(255, n), 0), t(n);
    forr(i, 0, n) f[RB(i + k)]++;
    int sum = 0;
    forr(i, 0, max(255, n)) f[i] = (sum += f[i]) - f[i];
    forr(i, 0, n) t[f[RB(sa[i] + k)]++] = sa[i];
    sa = t;
}
vector<int> constructSA(string &s)
{ // O(n logn)
    int n = s.size(), rank;
    vector<int> sa(n), r(n), t(n);
    forr(i, 0, n) sa[i] = i, r[i] = s[i];
    for (int k = 1; k < n; k *= 2)
    {
        csort(sa, r, k);
        csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        forr(i, 1, n)
        {
            if (r[sa[i]] != r[sa[i - 1]] || RB(sa[i] + k) != RB(sa[i - 1] + k))
                rank++;
            t[sa[i]] = rank;
        }
        r = t;
        if (r[sa[n - 1]] == n - 1)
            break;
    }
    return sa;
}


int main()
{
    FIN;
    string s;
    cin >> s;
    s += '$';
    vector<int> saa = constructSA(s);

    int tt;
    cin >> tt;
    while (tt--)
    {
        string p;
        cin >> p;
        ll l = 0, r = saa.size() - 1;
        ll m = p.size();
        bool found = false;
        while (l <= r)
        {
            ll med = l + (r - l) / 2;
            if (s.substr(saa[med], m) == p)
            {
                found = true;
                break;
            }
            else if (s.substr(saa[med], m) < p)
                l = med + 1;
            else
                r = med - 1;
        }
        cout << (found ? "Yes" : "No") << endl;
    }

    return 0;
}