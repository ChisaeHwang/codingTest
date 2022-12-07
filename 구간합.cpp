#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int a[100001], b, c, psum[100001], n, m;

int main(){

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // 1부터 채우기
		psum[i] = a[i] + psum[i - 1]; // 구간마다 합 넣기 
	}
	
	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		int sum = 0;
		sum = psum[c] - psum[b - 1]; // C까지 누적합과 B - 1 R까지의 누적합을 빼주면 됨 
		cout << sum << '\n';
	}
	

	return 0;	
}
