#include<bits/stdc++.h>
using namespace std;

int countDivisors(int n){
	int cnt = 0;
    int i = 1;
    while(i*i<=n){
        if(n % i == 0)
            cnt += 2;
        if(i*i == n)
        	cnt-=1;
        i++;
    }
    return cnt;
}

int main()
{
	int n; cin >> n;
	while(n--){
		int x; cin >> x;
		cout << countDivisors(x) << endl;
	}
	return 0;
}
