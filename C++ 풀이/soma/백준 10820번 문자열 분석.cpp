#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {		// ���ڿ��� �Է¹��� ������ �ݺ�
	    int a=0,b=0,c=0,d=0;
	    for (int i=0; i<s.size(); i++) {	// ���ڿ��� ���̸��� �ݺ�
		    if (s[i] >= 'a' && s[i] <= 'z') a++; // �ҹ��� ī��Ʈ 
		    else if (s[i] >= 'A' && s[i] <= 'Z') b++; // �빮�� ī��Ʈ 
		    else if (s[i] >= '0' && s[i] <= '9') c++; // ���� ī��Ʈ 
		    else if (s[i] == ' ') d++; // ���� ī��Ʈ 
	        }
	    cout << a << " " << b << " " << c << " " << d << '\n';
	}
	return 0;
}
