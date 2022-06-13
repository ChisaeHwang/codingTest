#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
char a[20];
vector<string> ans;
bool check[10];

bool good(char x, char y, char op){
	if(op == '<'){
		if (x < y) return true;
	}
	if(op == '>'){
		if (x > y) return true;
	}
	
	return false;
}

void go(int idx, string num) {
	if (idx == n+1){
		ans.push_back(num);
		return;
	}
	for(int i=0; i<=9; i++){
		if(check[i]) continue;
		if(idx == 0 || good(num[idx-1], i+'0', a[idx-1])){ // 이전, 선택, 부등호 
			check[i] = true;
			go(idx+1, num+to_string(i));
			check[i] = false;
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	// idx 0부터 string  빈공간 부터 
	go(0, "");
	
	auto p = minmax_element(ans.begin(), ans.end());
	cout << *p.second << '\n';
	cout << *p.first << '\n';
	
	return 0;
	
}
