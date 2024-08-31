#include <bits/stdc++.h>

using namespace std;

int n, ret, cnt;
int arr[11]; 
int visited[11];
vector<int> v;

void go() {
	
	if (v.size() == n) {
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += abs(v[i + 1] - v[i]);
		}
		ret = max(ret, temp);
		return;
	}


	for (int i = 1; i <= n; i++) { //백트래킹
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			go();
			v.pop_back();
			visited[i] = 0;
		}
	}
	
}

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	go();

	cout << ret << '\n';	
	
	return 0;
	
}


