#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)

bool isPossible( ll n,ll a[], ll sum, ll k){
    ll needed = 1, cum = 0, i = 0;
    while(i<n){
        if(cum+a[i]>sum){
            cum = a[i];
            needed++;
        }
        else cum+= a[i];
        i++;
    }
    return needed<=k ? true : false;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k; cin >> n >> k;
    ll a[n]; forn(i,n) cin >> a[i];
    
    ll M=-1,suma=0;
    forn(i,n){M = max(M,a[i]); suma+=a[i];}
    ll l = M ,r = suma; 
    while(l<=r){
        if(l==r){
            cout << l << endl;
            return 0;
        }

        ll med = (l+r)/2;
        if(isPossible(n,a, med,k) && !isPossible(n,a,med-1,k)){
            cout << med << endl;
            return 0;
        }
        if(!isPossible(n,a,med,k))
            l = med+1;
        else
            r = med;
    }

    return 0;
}
