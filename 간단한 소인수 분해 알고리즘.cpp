#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	if(n == 1) return 1;
	
	vector<int> ret;
	
	for(int div = 2; n > 1; div++){
		while(n % div == 0){
			n /= div;
			ret.push_back(div);
		}
	}
	
	return ret;
	
}
