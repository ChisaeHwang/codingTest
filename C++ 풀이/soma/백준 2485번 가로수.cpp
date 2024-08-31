#include <bits/stdc++.h>

using namespace std;

int n;
int tree[100001];
int sum[100001];
int cnt;

int gcd(int a, int b) { // a와 b를 나눈 나머지가 R이라고 할 때 
    if (b == 0) return a; // b와 R의 최대공약수는 a와 b의 최대공약수와 동일 
    return gcd(b, a % b ); // 그러므로 R이 없이 될 때까지 반복 
}				// R ▲ 

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
	}
	
	for (int i = 2; i <= n; i++) {
		sum[i - 1] = tree[i] - tree[i - 1];
	} // 트리끼리 간격 따로 저장 
	
	int temp = gcd(sum[2], sum[1]);
	
	for (int i = 3; i < n; i++) {
		temp = gcd(sum[i], temp);
	} // 간격의 최대 공약수 찾기 
	
	for (int i = 1; i < n; i++) {
		int ret = sum[i];
		while(ret > temp) {
			ret -= temp;
			cnt++;
		}
	} // 최대 공약수에 맞춰서 나무 심기 
	
	cout << cnt << '\n';

	return 0; 
}
