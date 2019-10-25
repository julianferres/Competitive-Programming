#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()

int findMaxGCD(int arr[],int n){
	int high = 0;
	forn(i,n) high = max(high,arr[i]);
	int count[high+1] = {0};
	forn(i,n) count[arr[i]]++;

	int counter = 0;

	for(int i = high; i>=1 ; i--){
		int j = i;
		counter = 0;

		while(j<=high){
			if(count[j]>=2) return j;
			else if(count[j]==1) counter++;

			j+=i;
			if(counter==2) return i;
		}
	}
	return 0;
}

int main()
{FIN;
	int n; cin >> n;
	int a[n]; forn(i,n) cin >> a[i];
	int ans = findMaxGCD(a,n);
	cout << ans << endl; 
    return 0;
}
