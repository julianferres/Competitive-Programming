/******************************************
*    AUTHOR:         julianferres         *
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
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define M 21 //2**23>10**6

int main()
{
    FIN;
    int n;
    cin >> n;
    vi a(n), b(1 << M), c(1 << M);
    forn(i, n) cin >> a[i], b[a[i]]++, c[a[i]]++;

    forn(i, M)
        forn(x, (1 << M))
    {
        if (x & (1 << i))
            //Si el x tiene prendido el i bit, lo podria apagar en y
            //Porque se sigue cumpliendo x|y=x
            b[x] += b[x ^ (1 << i)];
        else
            c[x] += c[x ^ (1 << i)];
        //Puedo prender el bit de y porque sigue siendo 0 con el and
    }
    for (auto x : a)
        cout << b[x] << " " << c[x] << " " << n - b[(1 << M) - 1 - x] << endl;

    return 0;
}
