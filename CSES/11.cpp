#include <bits/stdc++.h>
using namespace std;
  

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n , m;
	map <long long, long long> aparece,contador;
	set<long long> h;
	cin >> n >> m;
	int t[m];
	for(int i = 0; i<n ; i++){
		int a; cin >> a; h.insert(a);
	};
	for(int i = 0; i<m ; i++) cin >> t[i];
	sort(h.begin(),h.end());
	
	for(int i = 0; i<m ; i++){
		set<long long>::iterator r = h.upper_bound(t[i]);
		long aux = *r
		if(h.begin() == r) printf("-1\n");
		else{	
		printf("%d\n", h[r-1]);
		contador[aux]++;
		if(contador[aux]==aparece[aux]) h.erase(aux);
		}
	}
	return 0;
}