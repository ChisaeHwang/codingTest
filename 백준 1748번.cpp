#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	long long ans = 0;
	for(int start=1, len=1; start<=n; start*=10, len++){
		int end = start*10-1;
		if(end > n){
			end = n;
		}
		ans += (long long)(end - start + 1) * len; // 수의 갯수 * 수의 길이 
	}
	
	cout << ans << '\n';
	
	return 0; 
}
