#include <stdio.h>

int main(){

	int num1, num2, num3, temp;
	
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if(num2 >= num3){
		temp = num3;
		num3 = num2;
		num2 = temp;
	}
	if(num1 >= num2){
		temp = num2;
		num2 = num1;
		num1 = temp;
	}
	if(num1 >= num3){
		temp = num3;
		num1 = num3;
		num3 = temp;
	}
	if(num2 >= num3){
		temp = num3;
		num3 = num2;
		num2 = temp;

	}
	
	printf("%d", num2);

}
