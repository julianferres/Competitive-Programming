#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0)
#define fore(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
	forn(i, n) cout << v[i] << " "; \
	cout << endl
#define RAYA cerr << "===============================" << endl
#define MAXN 200005
#define MAXN2 400005

int n, q, a, b;
ll t[2 * MAXN2], initvalue[MAXN];
vi g[MAXN], s, le(MAXN, -1), ri(MAXN, -1);
bool vis[MAXN];

void build()
{ // build the tree
	for (ll i = n - 1; i > 0; --i)
		t[i] = t[i << 1] + t[i << 1 | 1];
}
void modify(ll p, ll value)
{ // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = t[p] + t[p ^ 1];
}
ll query(ll l, ll r)
{ // sum on interval [l, r)
	ll res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res += t[l++];
		if (r & 1)
			res += t[--r];
	}
	return res;
}

void dfs(ll v)
{
	s.pb(v);
	vis[v] = true;
	for (auto u : g[v])
	{
		if (vis[u])
			continue;
		dfs(u);
	}
	s.pb(v);
}

void init_lr()
{
	forn(i, s.size())
	{
		if (le[s[i]] == -1)
			le[s[i]] = i;
		else
			ri[s[i]] = i;
	}
}

int main()
{
	FIN;
	cin >> n >> q;

	forn(i, n) cin >> initvalue[i];
	forn(i, n - 1)
	{
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	init_lr();
	n *= 2;
	forn(i, n) t[i + n] = initvalue[s[i]];
	build();
	init_lr();

	forn(i, q)
	{
		ll c, ss, x;
		cin >> c;
		if (c & 1)
		{
			cin >> ss >> x;
			ss--;
			modify(le[ss], x);
			modify(ri[ss], x);
		}
		else
		{
			cin >> ss;
			ss--;
			ll ans = query(le[ss], ri[ss] + 1) / 2;
			cout << ans << endl;
		}
	}

	return 0;
}