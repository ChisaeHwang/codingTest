#include <cstdio>
int arr[1001];
void calc() {
	int cnt = 1;

	for (int i = 0; i < 1001;) {

		for (int j = 0; j < cnt; j++) {
			arr[i++] = cnt;
		}
		cnt++;
	}
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	calc();//���� �̸� ���س���
	
	int ans = 0;
	for (int i = a-1; i < b; i++) {
		ans += arr[i];
	}
	printf("%d", ans);
	return 0;
}
