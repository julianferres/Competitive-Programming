#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  ll dsum = 0;
  vector<int> durations;
  forn(i,n){
  	ll a,d; cin >> a >> d;
  	dsum+=d; durations.pb(a);
  }
  ll fsum = 0;
  sort(durations.begin(), durations.end());
  forn(i,n) fsum+= (n-i)*durations[i];
  cout << dsum-fsum << endl;

  return 0;
}
