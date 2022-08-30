#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set> 

using namespace std;

int main() {
	
	string s;
	cin >> s;
	
	set<string> set;
	
	int len = s.size();
	
	string str = "";
	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
		str += s[j];
		set.insert(str);	
		}
		str = "";
	}
	
	cout << set.size() << '\n';
	
	return 0;
}
