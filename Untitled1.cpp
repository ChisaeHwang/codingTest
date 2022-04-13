#include <stdio.h>

int main(){

	int n, k, i, arr[10000], min = 24;
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		arr[i] = k;
	}
	
	for (i=0; i<n; i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	
	printf("%d ", min);
	
	return 0;
}


