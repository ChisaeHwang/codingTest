#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	string str;
	string temp[1000];
	cin >> str;
	int len = str.length();
	
	for(int i=0; i<len; i++){
		temp[i] = str.substr(i, len); // SUBSTR("문자열", "시작위치", "길이") 문자열 자를 때 사용 
		// 앞글자 하나씩 컷 
	}
	
	sort(temp, temp+len); // 오름차순으로 정렬 (사전순 정렬) 
	
	for(int i=0; i<len; i++){
		cout << temp[i] << '\n';
	} 
	
	 
	return 0;
    
}


