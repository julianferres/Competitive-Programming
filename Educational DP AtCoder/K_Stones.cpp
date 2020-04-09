/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll INF = 1<<30 ;
const int N = 100005;

const int K = 100005;
vector<int> loss(K,-1);
int n; vector<int> a(N);

int fill(int k){
	if(loss[k]!=-1) return loss[k];
	bool win = 0;
	forn(i,n){
		if(k-a[i]>=0) win |= (fill(k-a[i]));
	}

	loss[k] = 1-win;
	return loss[k];
}

int main(){
    FIN;
    int k; cin >> n >> k;
    forn(i,n) cin >> a[i];
    int m = INF;
    forn(i,n) m = min(m,a[i]);

    forn(i,m) loss[i] = 1;
    // forn(i,k+1) cout << loss[i] << " \n"[i==k];
    fill(k);
    // forn(i,k+1) cout << loss[i] << " \n"[i==k];
    cout << (loss[k] ? "Second" : "First") << endl;

    return 0;
}

