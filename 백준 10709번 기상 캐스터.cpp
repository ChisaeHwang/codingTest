#include <bits/stdc++.h>
 
 using namespace std;
 
 int arr[101][101];
 int h, w;
 string s;
 
 int main() {
 	
 	cin >> h >> w;
 	
 	for (int i = 0; i < h; i++){
 		cin >> s;
 		for (int j = 0; j < w; j++){
 			 if(s[j] == '.') {
 				arr[i][j] = -1;
			 } else {
			 	arr[i][j] = 0;
			 }
		}
	}
	
	for (int i = 0; i < h; i++){
 		for (int j = 0; j < w; j++){
 			if (arr[i][j] == 0) {
 				int cnt = 1;
 				while(arr[i][j + 1] == -1) { // ���� 0�̸� �������ͼ� �ٽ� ���� 
 					arr[i][j + 1] = cnt++;
 					j++;
				 }
			 }
		 }
	 }
	 
	 
	for (int i = 0; i < h; i++){
 		for (int j = 0; j < w; j++){
 			cout << arr[i][j] << " ";
		 }
		 cout << '\n';
	 }
 	
 	
 	
 	return 0;
 }
