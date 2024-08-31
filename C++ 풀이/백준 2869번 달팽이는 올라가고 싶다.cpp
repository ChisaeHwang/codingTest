#include <iostream>

using namespace std;

// 반복문 쓰면 무조건 틀리는 문제 

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
