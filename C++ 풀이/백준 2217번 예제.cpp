#include <stdio.h>
#include <stdlib.h>


int compare(const void* first, const void* second) {
	if (*(int*)first < *(int*)second)
		return -1;
	else if (*(int*)first > *(int*)second)
		return 1;
	else
		return 0;
}


int main() {

	int n; //줄 갯수
	int w[100001];	//로프 마다 중량
	int kw=0;			//최대 중량

	scanf("%d", &n);	//로프 갯수

	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);			//로프마다의 중량 입력
	}

	qsort(w, n, sizeof(int), compare);	// 중량을 오름차순 정렬

	for (int i = 0; i < n; i++) {		
		if (kw < w[i] * (n - i))		//현재 i로프의 최대 중량 * 현재 로프 수
			kw = w[i] * (n - i);
	}

	printf("%d", kw);

	return 0;
}
