#include <iostream>
#include <algorithm>
using namespace std;

int freg[26];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){
    	freg[str[i] - 97]++; // �ƽ�Ű�ڵ带 �̿��� Ǯ�� 
	}
	
	for(int i=0; i<26; i++){
		cout << freg[i] << " ";
	}
	
	 
	return 0;
    
}


