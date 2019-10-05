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
	int n; cin >> n;
n = int(input())
a = []
for i in range(n):
	s,e = map(int,input().split())
	a.append((s,"(",i))
	a.append((e,")",i))
a.sort()

ans = 0
act = 0
for x in a:
	if(x[1]=='('):
		act+=1
	else:
		act-=1
	ans = max(ans,act)
actRoom = 0
room = [0]*n
for x in a:
	if(x[1]=='('):
		room[x[2]] = actRoom+1
		actRoom = (actRoom+1)%ans
print(ans)
print(*room)