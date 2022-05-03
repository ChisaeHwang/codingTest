#include <iostream> 
#include <algorithm>
using namespace std;

int k[100] = {};

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t, n, num = 0;
	cin >> t;
	
	while(t--){
		cin >> n;
		int result = 0;
		num += 1;
		cout << "Class " << num << '\n';
		
		for(int i=0; i<n; i++){
			cin >> k[i];
		}
		
	    sort(k, k + n, greater<int>());
			
		for(int i=0; i<n-1; i++){ //  [0 1] [1 2] [2 3] [3 4] 
			if (result < k[i] - k[i+1]){
				result = k[i] - k[i+1];
			}
		}
		
		cout << "Max " << k[0] << ", Min " << k[n-1] << ", Largest gap " << result << '\n';
	}
	
	return 0;
}
