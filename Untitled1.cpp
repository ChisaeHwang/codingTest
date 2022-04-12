#include<stdio.h>

int main(){
 
	long long int a, m, d, n;
	
	scanf("%lld %lld %lld %lld", &a, &m, &d, &n);
	
	for(int i=1; i<m; i++){
		a *= m;
		a += d;
	}
	
	printf("%lld", a);
		
    return 0;
}



