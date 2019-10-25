#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz size()
#define forn(i,n) for(ll i=0; i<n; i++)
#define MOD 1000000007
typedef vector<vector<ll> > Matrix;
 
Matrix ones(int n){
    Matrix r(n,vector<ll>(n));
    forn(i,n) r[i][i] = 1LL;
    return r;
}
Matrix operator*(Matrix &a, Matrix &b){
    int n=a.sz, m = b[0].sz, z = a[0].sz;
    Matrix r(n,vector<ll>(m));
    forn(i,n) forn(j,m) forn(k,z)
        r[i][j]+= a[i][k]*b[k][j],r[i][j]%=MOD;
    return r;
}
Matrix be(Matrix b, ll e){
    Matrix r=ones(b.sz);
    while(e){if(e&1LL) r=r*b;b=b*b;e/=2;}
    return r;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    Matrix t(6,vector<ll>(6));
    forn(i,5) t[i][i+1]=1;
    forn(i,6) t[5][i]=1;
    Matrix res(6,vector<ll>(1));
    res[0][0]=1;res[1][0]=1;res[2][0]=2;
    res[3][0]=4;res[4][0]=8;res[5][0]=16;
    if(n<=5){
        cout << res[n][0] << endl;
        return 0;
    }
    Matrix pot = be(t,n-5);
    res = pot*res;
    cout << res[5][0] << endl;
    return 0;
}
