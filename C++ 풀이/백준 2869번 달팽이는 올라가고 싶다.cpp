#include <iostream>

using namespace std;

// �ݺ��� ���� ������ Ʋ���� ���� 

int main() {
	
	int a, b, v;
	
	cin >> a >> b >> v;
	
	int temp = 1;
	  temp += (v-a)/(a-b);
    if((v-a)%(a-b) != 0)
        temp++;
    if(a >= v)
        cout << "1";
    else
        cout << temp;
	
	return 0; 
}
