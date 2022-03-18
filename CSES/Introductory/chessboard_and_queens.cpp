#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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

vi b;
string a[8];
int c=0;

void f(int i){
	if(i==8){c++; return;}
	forn(j,8){
		if(a[i][j]=='*') continue;
		bool ok = true;
		forn(k,i){
			if(b[k]==j || b[k]==j+(i-k) || b[k]== j-(i-k)){
				ok = false;
				break;
			}
		}
		if(!ok) continue;
		b.pb(j);
		f(i+1);
		b.pop_back();
	}
}

int main(){ 
	FIN;
	forn(i,8) cin >> a[i];
	f(0); cout << c << endl;

	return 0;
}