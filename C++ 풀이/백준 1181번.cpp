#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

bool comp(string s1, string s2){
	if(s1.length() == s2.length()){
		return s1 < s2;	//string »çÀü¼ø 
	}
	else{
		return s1.length() < s2.length();
	}
}

string arr[20000];
int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> arr[i];
	}

	sort(arr, arr + t, comp);
	
	for(int i=0; i<t; i++){
		if(arr[i] == arr[i-1]){
			continue;
		}
		cout << arr[i] << '\n';
	}	
	
    return 0;
}

 
