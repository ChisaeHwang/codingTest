#include <stdio.h>

int main(){

	int panel[11][11] = {}; //[����][����] 
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			scanf("%d", &panel[i][j]);
		}
	}
	
	int x, y;
	x = 2;
	y = 2;
	
	while(1){
		
		// ������ �� ������ ���η� + 
		if(panel[x][y] == 0){
			panel[x][y] = 9;
			y++;
		}
		
		// ���� ������ ���η� �ϳ� - ���Ŀ�  ���η� �ϳ� + 
		if(panel[x][y] == 1){
			y--;
			x++;
		}
		
		// ���̸� ã�� ��� 
		if(panel[x][y] == 2){
			panel[x][y] = 9;
			break;
		}
		
		
		// �� �Ʒ��� ���� �����ʿ� ������ ���, �� �̻� ������ �� ���� ���, ���̸� ã�� ���
		else if(panel[x][y+1] == 1 && panel[x+1][y] == 1){
			if(panel[x][y] == 0){
				panel[x][y] = 9;
			}
			break;
		}	
	}
	
	// ����ϱ� 
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			printf("%d ", panel[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}



