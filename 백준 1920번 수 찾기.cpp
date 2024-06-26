#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set> 

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin >> n;
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		
		if (binary_search(v.begin(), v.end(), num))
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
		
	}
	

	return 0;
}
