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
    cin.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define SZ(x) ((int)x.size())
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1 << 30; // const ll INF = 1LL<<60;
const int MOD = 1e9 + 7; // 998244353
const int MAXN = 1e5 + 5;

typedef int tipo;
vector<tipo> t;
int tam;

void build(vector<ll> &v, int n)
{ // build the tree
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n);
    tam = 1 << tam;
    t.resize(2 * tam, INF);
    forn(i, n) t[tam + i] = v[i];
    for (tipo i = tam - 1; i > 0; i--)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, tipo value)
{ // set value at position p
    for (t[p += tam] = value; p > 1; p >>= 1)
        t[p >> 1] = min(t[p], t[p ^ 1]);
    //Tener cuidado aca, podria ser que en cosas no conmutativas, para p impar: p > p^1.
}

tipo query(int l, int r)
{ // min on interval [l, r]
    tipo res = INF;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, t[l++]);
        if (!(r & 1))
            res = min(res, t[r--]);
    }
    return res;
}

int main()
{
    FIN;

    int n, m;
    cin >> n >> m;
    vi a(n, INF);
    build(a, n);

    forn(i, m){
        // DBG(i);
        int tipo;
        cin >> tipo;
        if (tipo == 1){
            int idx, value;
            cin >> idx >> value;
            modify(idx, value);
            // forr(i, tam, 2*tam) cout << t[i] << " ";
            // cout << endl;
        }
        else{
            int ll, rr, p;
            cin >> ll >> rr >> p;
            rr--;
            if (query(ll, rr) > p){ // No tumba nada
                cout << "0\n";
                continue;
            }
            int ans = 0;
            while(query(ll, rr) <= p){
                ans++;
                int l = ll, r = rr;
                while (l < r){
                    int med = (l + r) / 2;
                    if (query(l, med) <= p)
                        r = med;
                    else
                        l = med + 1;
                }
                modify(l, INF);
                // DBG(l);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
