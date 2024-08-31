#include <stdio.h>

int main(){

	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a+b>c&&b+c>a&&a+c>b){
		if(a == b && a == c){
			printf("Á¤»ï°¢Çü");
		}else if(a==b || b == c || a == c){
			printf("ÀÌµîº¯»ï°¢Çü");
		}else if(a*a + b*b == c*c){
			printf("Á÷°¢»ï°¢Çü");
		}else{
			printf("»ï°¢Çü");
		}
	}else
	
	printf("»ï°¢Çü¾Æ´Ô");
	
	return 0;
}
