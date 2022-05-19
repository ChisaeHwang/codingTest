#include <iostream>
#include <string>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--){
		int a, b, cnt=0;
		cin >> a >> b;
		for(int i=a; i<=b; i++){
			string str = to_string(i);
			for(int j=0; j<str.length(); j++){
				if(str[j] == '0'){
					cnt++;
				}
			}
		}
		
		cout << cnt << '\n';
	}
	
	
	return 0;
	
}
