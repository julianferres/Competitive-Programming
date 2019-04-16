#include <bits/stdc++.h>
using namespace std;

int main() {
	long n, m, x;
	map <long long, long long> belongs, cnt;
	scanf ("%ld %ld", &n, &m);  
	set <long long> ms;
	set<long long>::iterator itlow,itup;
	for(long i=0; i<n; i++)
	{
		scanf ("%ld",&x);  
		ms.insert(x);
		belongs[x]++;
	}
	for(long i=0; i<m; i++)
	{
		scanf ("%ld",&x);  
		itlow=ms.lower_bound (x+1);
		if(itlow==ms.begin()) cout << "-1" << endl;
		else
		{
			itlow--;
			long aux=*itlow;
			printf ("%ld \n", aux);  
			cnt[aux]++;
			if(cnt[aux]==belongs[aux]) ms.erase(aux);
		}
	}
	return 0;
}