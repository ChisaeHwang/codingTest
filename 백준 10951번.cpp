#include <iostream>
using namespace std;

int main(){

    int a,b;    
    while (!(cin >> a >> b).eof()) // eof : end-of-file 파일의 끝을 의미함
    {   
        cout << a + b << "\n";
    }

    
	return 0; 
}
