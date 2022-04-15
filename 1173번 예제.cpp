#include <stdio.h>

int main(){

	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if(b < 30){
		a--;
		b += 60;
		
		if(a < 0){
		a += 24;
		}
	}
	
	b -= 30;
	
	printf("%d %d", a, b);
	
	return 0;
}
