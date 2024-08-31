#include <iostream>
#include <vector>
#include <algorithm>¤Á
#include <string> 

using namespace std;

int main() {
	
	int n, m;
	string str;
	vector<string> v, ans;
	int cnt;
	
	cin >> n >> m;
	
	for(int i = 0; i < n + m; i++){
		cin >> str;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n + m - 1; i++){
		if(v[i] == v[i + 1]){
			ans.push_back(v[i]);
			cnt++;
		}
	}
	
	cout << cnt << '\n';
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << '\n';
	}
	
	
	
	
	return 0;
}
