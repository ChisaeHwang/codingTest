#include<stdio.h>

int main(){
 
	int a, b, c;
    
    printf("국어 영어 수학 점수를 입력하시오: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("국어 : %d \n", a);
    printf("영어 : %d \n", b);
    printf("수학 : %d \n", c);
    
    float sum = a + b + c;   
    printf("총점 : %.0f \n", sum);
    
    float ave = sum / 3;
    printf("평균 : %.2f \n", ave);
    
	int rank = 0; 
	 
	if(ave > 100 || ave < 0){
		printf("잘못된 점수를 입력하셨습니다.");
			
		return 0;
	}else{	
	
		if(ave >= 90){
			printf("등급 : A \n");
			rank = 1;
		}else if 
			(ave >= 80){
				printf("등급 : B \n");
				rank = 1; 
		}else if
			(ave >= 70){
				printf("등급 : C \n");
				rank = 2;
		}else if
			(ave >= 60){
				printf("등급 : D \n");
				rank = 2;
		}else{
				printf("등급 : F \n");
				rank = 3;
			}
		
	    
	    switch(rank){
	    	case 1:
	    		printf("조치사항 : 장학금을 받으세요");
	    		break;
	    	case 2:
	    		printf("조치사항 : 보충 수업을 들으세요");
	    		break;
	    	case 3:
	    		printf("조치사항 : 재수강바랍니다.");
	    		
		}
	}
		
    return 0;
}


