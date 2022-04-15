#include <stdio.h>

int main(){

	int a, b;
	
	scanf("%d %d", &a, &b);
	
	for(int i=a; i<90; i+=5){
		b += 1;
		
	}
	
	printf("%d", b);
	
	return 0;

}
