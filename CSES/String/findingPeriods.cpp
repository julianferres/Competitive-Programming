#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

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
	string s; cin >> s; int n = s.sz;
	vi z = zeta(s);
	vi ans; ans.pb(n);
	fore(i,1,n){
		if(z[i]+i>=n){ans.pb(i); continue;}
		if(z[i]>=i){
			int aux = i;
			while(aux<n-i && z[aux]>=i) aux+=i;
			if(aux>=n-i)
				if(aux>=n || z[aux]+aux>=n) ans.pb(i);
		}
	}
	sort(ans.begin(), ans.end());
	forn(i,ans.sz) cout << ans[i] << " ";
	cout << endl;

	return 0;
}