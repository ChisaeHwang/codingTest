#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {		// 문자열을 입력받을 때마다 반복
	    int a=0,b=0,c=0,d=0;
	    for (int i=0; i<s.size(); i++) {	// 문자열의 길이마다 반복
		    if (s[i] >= 'a' && s[i] <= 'z') a++; // 소문자 카운트 
		    else if (s[i] >= 'A' && s[i] <= 'Z') b++; // 대문자 카운트 
		    else if (s[i] >= '0' && s[i] <= '9') c++; // 숫자 카운트 
		    else if (s[i] == ' ') d++; // 공백 카운트 
	        }
	    cout << a << " " << b << " " << c << " " << d << '\n';
	}
	return 0;
}
