#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int x)
{
    return x && (!(x&(x-1)));
}
#define m 1000000007
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y) //pii p;   //p=mp(3,5);
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

inline ll prodm(ll a,ll b)
{
  return((a%m)*(b%m))%m;
}

inline ll summ(ll a,ll b)
{
  return ((a%m)+(b%m))%m;
}

const int N = 1e6 + 5;


void pehla(int **pascal,ll p)
{
  pascal[0][0]=1;
  for(int i=1;i<p;i++)
  {
    pascal[i][0]=1;
    for(int j=i;j>0;j--)
    {
      pascal[i][j]=(pascal[i-1][j]%p+pascal[i-1][j-1]%p)%p;
    }
  }
  return;
}

ll ncrmodp(ll n,ll r,ll p,int **pascal)
{
  if(r==0)
    return 1;
  int ni=n%p,ri=r%p;

  return ((ncrmodp(n/p,r/p,p,pascal)%p)*pascal[ni][ri])%p;
}



int main()
{ boost;
  ll n,r,T;
  int i,j;
  int p=m;
  int **pascal=new int*[p];
  for(i=0;i<p;i++)
  {
    pascal[i]=new int[p];
    for(j=0;j<p;j++)
      pascal[i][j]=0;
  }
  pehla(pascal,p);
  cin>>T;
  while(T--)
  {
    cin>>n>>r;


  ll ans=ncrmodp(n,r,p,pascal);
  cout<<ans<<"\n";
}
  return 0;
}
