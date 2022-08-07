#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

string s;
int dp[500][500];

int go(int l, int r) {
	
	if (l >= r) return 0;
	
	int& result = dp[l][r];
	if(result != -1) return result;
	
	int ans = -1;
	
	for(int k = l; k < r; ++k){
		ans = max(ans, go(l, k) + go(k + 1, r));
	}
	
	if((s[l] == 'a' && s[r] == 't')||(s[l] == 'g' && s[r] == 'c')){
		ans = max(ans, go(l + 1, r - 1) + 2);
	}
	
	return result = ans;
	
}

int main() {
	
	
	memset(dp, -1, sizeof(dp));
	
	cin >> s;
	
	cout << go(0, s.length() -1) << '\n';
	
	return 0; 
} 
