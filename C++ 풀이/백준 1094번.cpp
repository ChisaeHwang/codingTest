#include <stdio.h>

int main(){

	int a; 
	
	

	scanf("%d", &a);
	
	int result = 0;
	while(a>0){
		if(a % 2 == 1){
			result++;
		}
		a /= 2;
	}
	
	printf("%d", result);

	return 0; 
}
