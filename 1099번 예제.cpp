#include <stdio.h>

int main(){

	int panel[11][11] = {}; //[가로][세로] 
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			scanf("%d", &panel[i][j]);
		}
	}
	
	int x, y;
	x = 2;
	y = 2;
	
	while(1){
		
		// 막히기 전 까지는 가로로 + 
		if(panel[x][y] == 0){
			panel[x][y] = 9;
			y++;
		}
		
		// 벽에 막히면 가로로 하나 - 이후에  세로로 하나 + 
		if(panel[x][y] == 1){
			y--;
			x++;
		}
		
		// 먹이를 찾은 경우 
		if(panel[x][y] == 2){
			panel[x][y] = 9;
			break;
		}
		
		
		// 맨 아래의 가장 오른쪽에 도착한 경우, 더 이상 움직일 수 없는 경우, 먹이를 찾은 경우
		else if(panel[x][y+1] == 1 && panel[x+1][y] == 1){
			if(panel[x][y] == 0){
				panel[x][y] = 9;
			}
			break;
		}	
	}
	
	// 출력하기 
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			printf("%d ", panel[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}



