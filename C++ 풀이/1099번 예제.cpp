#include <stdio.h>

int main(){

	int a, sum;
	
	a = 1;
	sum = 0; 
	 
	while(a!=0){	
		printf("���ڸ� �Է��Ͻÿ�(���� ��0) : ");
		scanf("%d", &a);
	
		if(a % 2 == 0){
			for(int i=1; i<=a; i++ ){	 
				 sum = sum + i;
				 
			}
		}
		
		printf("%d ������ ���� %d �Դϴ�", a, sum);
		
		return 0;
		
	}

}
  
