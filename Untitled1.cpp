#include<stdio.h>

int main(){

	int a, b, c;
	
	int day = 1;
	
	scanf("%d %d %d", &a, &b, &c);
	
	while(day%a || day%b || day%c){
		day++;
	}
	
	printf("%d", day);
	
	return 0;
}


