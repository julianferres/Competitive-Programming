#include <bits/stdc++.h>
using namespace std;

bool esprimo(long long n)
{
	for(long i=2; i*i<=n; i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main() {
	long long n;
	while(scanf("%ld", &n)==1)
	{
		if(n==2) printf("1\n");
		else if(n%2==0) printf("2\n");
		else if(esprimo(n)==true) printf("1\n");
		else if(esprimo(n-2)==true) printf("2\n");
		else printf("3\n");
	}
	return 0;
}
