#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n, q;
	cin >> n >> q;
	ll a[n+1];
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) a[i]+=a[i-1];

	while(q--){
		int l,r;
		cin >> l >> r;
		cout << a[r]-a[l-1] << endl;
	}
	return 0;
}

