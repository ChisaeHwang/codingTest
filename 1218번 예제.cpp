#include <stdio.h>

int main(){

	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a+b>c&&b+c>a&&a+c>b){
		if(a == b && a == c){
			printf("���ﰢ��");
		}else if(a==b || b == c || a == c){
			printf("�̵�ﰢ��");
		}else if(a*a + b*b == c*c){
			printf("�����ﰢ��");
		}else{
			printf("�ﰢ��");
		}
	}else
	
	printf("�ﰢ���ƴ�");
	
	return 0;
}
