#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n;
	cin >> n;
	
	vector<pair<pair<int, int>, pair<int, string>>> v(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i].second.second >> v[i].second.first >> v[i].first.second >> v[i].first.first;
		
		// 이름 , 일, 월, 년도 
	}
	
	sort(v.begin(), v.end());
	
	
	cout << v[n-1].second.second << "\n" << v[0].second.second << "\n";
	
	// 가자 나이 적은사람, 많은 사람 
    return 0;
}

  
