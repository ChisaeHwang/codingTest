#include<stdio.h>

int main(){
 
	int a, b, c;
    
    printf("���� ���� ���� ������ �Է��Ͻÿ�: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("���� : %d \n", a);
    printf("���� : %d \n", b);
    printf("���� : %d \n", c);
    
    float sum = a + b + c;   
    printf("���� : %.0f \n", sum);
    
    float ave = sum / 3;
    printf("��� : %.2f \n", ave);
    
	int rank = 0; 
	 
	if(ave > 100 || ave < 0){
		printf("�߸��� ������ �Է��ϼ̽��ϴ�.");
			
		return 0;
	}else{	
	
		if(ave >= 90){
			printf("��� : A \n");
			rank = 1;
		}else if 
			(ave >= 80){
				printf("��� : B \n");
				rank = 1; 
		}else if
			(ave >= 70){
				printf("��� : C \n");
				rank = 2;
		}else if
			(ave >= 60){
				printf("��� : D \n");
				rank = 2;
		}else{
				printf("��� : F \n");
				rank = 3;
			}
		
	    
	    switch(rank){
	    	case 1:
	    		printf("��ġ���� : ���б��� ��������");
	    		break;
	    	case 2:
	    		printf("��ġ���� : ���� ������ ��������");
	    		break;
	    	case 3:
	    		printf("��ġ���� : ������ٶ��ϴ�.");
	    		
		}
	}
		
    return 0;
}


