#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int visited[31];
int a;

int main() {
	
	memset(visited, 0, sizeof(visited));
	
	for (int i = 1; i <= 28; i++) {
		cin >> a;
		visited[a] = 1;			
	}
	
	for (int i = 1; i <= 30; i++){
		if (!visited[i]) {
			v.push_back(i);
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v[0] << '\n' << v[v.size() - 1] << '\n';
	
	return 0;
}
