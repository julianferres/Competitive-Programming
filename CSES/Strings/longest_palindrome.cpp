#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) fore(i, 0, n)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

string longestPalindrome(string s) 
{
    string T;// Transform S to T
    for(int i=0;i<s.size();i++)
        T+="#"+s.substr(i,1);
    T.push_back('#');

    vector<int> P(T.size(),0); // Array to record longest palindrome
    int center=0,boundary=0,maxLen=0,resCenter=0;
    for(int i=1;i<T.size()-1;i++) {
        int iMirror=2*center-i; // calc mirror i = center-(i-center)
        P[i]=(boundary>i)?min(boundary-i,P[iMirror]):0; // shortcut
        while(i-1-P[i]>=0&&i+1+P[i]<=T.size()-1&&T[i+1+P[i]] == T[i-1-P[i]]) // Attempt to expand palindrome centered at i
            P[i]++;
        if(i+P[i]>boundary) { // update center and boundary
            center = i;
            boundary = i+P[i];
        }
        if(P[i]>maxLen) { // update result
            maxLen = P[i];
            resCenter = i;
        }    
    }
    return s.substr((resCenter - maxLen)/2, maxLen);
}

int main(){ 
	FIN;
	string S; cin >> S;
	cout << longestPalindrome(S)<< endl;

	return 0;
}