#include <bits/stdc++.h>
long M = 1000000007;
long power(long a, long b){

	long ans;
	if(b==0) return 1;
	if(b%2==0){ ans = power(a,b/2); ans = (ans*ans)%M;}
	else{ans =power(a,b-1); ans=(ans*a)%M;}
	return ans;
}

int main(){
	long n,x,y;
	scanf("%ld",&n);
	for(long i=0;i<n;i++){
		scanf("%ld %ld",&x,&y);
		printf("%ld\n" , power(x,y));
	}
	return 0;
}