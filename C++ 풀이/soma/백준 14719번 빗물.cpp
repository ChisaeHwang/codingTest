#include <bits/stdc++.h>

using namespace std; 

int main() {
	
	int w, h;
	int cnt = 0;
	
	cin >> h >> w;
	
	vector<int> v(w); 
	
	for (int i = 0; i < w; i++) {
		cin >> v[i];
	}
	
	for (int i = 1; i < w - 1; i++) {
		int left = 0; 
		int right = 0;
		
		for(int j = 0; j < i; j++) { // 왼쪽 제일 큰값 
			left = max(left, v[j]);
		}
		
		for (int j = w - 1; j > i; j--) { // 오른쪽 제일 큰 값 
			right = max(right, v[j]);
		}
		
		cnt += max(0, min(left, right) - v[i]);
		// v[i] 는 현재 위치의 높이이므로 빼야함 
	}
	
	cout << cnt << '\n';
	
	return 0;
}
