#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int cnt[26];

int main() {
	 
	string str;
	cin >> str;
	
	for (char a : str) {
		cnt[a - 97]++;
	}
	
	for (int i = 0; i < 26; i++){
		cout << cnt[i] << " ";
	}
	
	return 0; 
}
