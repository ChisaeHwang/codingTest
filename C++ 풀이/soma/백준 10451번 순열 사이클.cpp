#include <bits/stdc++.h>

using namespace std;

int t, n, a, ret;
vector<int> v[1001];
int arr[1001];

void dfs(int num) {
	arr[num] = 1; // 방문체크 
	for(int i = 0; i < v[num].size(); i++){
		int next = v[num][i];
		if(arr[next] == 0){ // 아직 방문 안 함 
			dfs(next); 
		}
	}
}

int main() {
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		int cnt = 0;
		
		for(int i = 1; i <= n; i++){
			v[i].clear();
			arr[i] = 0;
		}
		
		for (int i = 1; i <= n; i++) {
			cin >> a;
			v[i].push_back(a);
			v[a].push_back(i);
		}
		
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) { // 방문 안했을 시 
				dfs(i);
				cnt++;
			}
		}
		
		cout << cnt << '\n';
		
	}
	
	
	
	return 0;
} 
