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
		temp[i] = str.substr(i, len); // SUBSTR("���ڿ�", "������ġ", "����") ���ڿ� �ڸ� �� ��� 
		// �ձ��� �ϳ��� �� 
	}
	
	sort(temp, temp+len); // ������������ ���� (������ ����) 
	
	for(int i=0; i<len; i++){
		cout << temp[i] << '\n';
	} 
	
	 
	return 0;
    
}


