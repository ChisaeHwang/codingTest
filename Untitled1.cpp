#include<stdio.h>

int main(){

    int n, a;
    
    scanf("%d %d", &n ,&a);
    
    for (int i=1; i<=n; i++){
	    if(i % 3){
	        printf("%d ", i);
		}
	}
	
 	for(int j = 1; j <=a; j++){
        if(j % 5 == 0){
            continue;
        }
        else{
            printf("%d ",j);
        }
    }
    
    return 0;
}


