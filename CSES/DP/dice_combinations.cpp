#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	long long MOD = 1000000007;
	long long array[7] = {1,1,2,4,8,16,32};

	if(n<=6){
		cout << array[n] << "\n";
		return 0;
	}
	for(int i = 7; i<n+1;i++){
		long long cum = 0;
		for(int j = 1; j<=6;j++){
			cum+= array[7-j];
		}
		for(int k = 1; k<7;k++) array[k-1] = array[k];
		array[6] = (cum+MOD)%MOD;
	}

	cout << (array[6]+MOD)%MOD << "\n";
	return 0;
}