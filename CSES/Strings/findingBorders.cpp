#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)

vi zeta(string s) {
    int n = (int) s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main(){ 
	FIN;
	string s; cin >> s;
	vi z = zeta(s);
	int n = s.size();
	vi ans;
	forn(i,n) if(z[i]+i==n) ans.pb(n-i);
	reverse(ans.begin(), ans.end());
	forn(i,ans.size()) cout << ans[i] << " ";

	cout << endl;
	return 0;
}