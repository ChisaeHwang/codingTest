#include <stdio.h>

int main(){

	int a, sum;
	
	a = 1;
	sum = 0; 
	 
	while(a!=0){	
		printf("숫자를 입력하시오(종료 시0) : ");
		scanf("%d", &a);
	
		if(a % 2 == 0){
			for(int i=1; i<=a; i++ ){	 
				 sum = sum + i;
				 
			}
		}
		
		printf("%d 까지의 합은 %d 입니다", a, sum);
		
		return 0;
		
	}

}
  
