#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define ii pair<int,int>
#define forn(i,n) for(int i=0; i<n; i++)

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,x; cin >> n >> x;
	vector< pair<int,int> > a;
	forn(i,n){
		int x; cin >>x;
		a.pb(mp(x,i));
	}
	sort(a.begin(), a.end());

	forn(i,n){
		int pa = i+1; int pb = n-1;
		int target = x-a[i].F;
		while(pa<pb){
			if(a[pa].F+a[pb].F==target){
				printf("%d %d %d\n", a[pa].S+1,a[pb].S+1,a[i].S+1);
				return 0;
			}
			else if(a[pa].F+a[pb].F<target) pa++;
			else pb--;
		}
	}
  	puts("IMPOSSIBLE");
  	return 0;
}
