#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;
    
    int len = str.length();
    
    sort(str.begin(), str.end(), greater<char>());
    for(int i=0; i<str.length(); i++){
    	cout << str[i];
	}
	
	return 0;
    
}


