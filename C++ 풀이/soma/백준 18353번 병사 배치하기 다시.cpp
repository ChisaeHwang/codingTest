#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2001];
int dp[2001];

vector<int> split(const string s, char del) {
	vector<string> tokens;
	string token;
	isStringstream tokenStream(s);
	
	while(getline(tokenStream, token, del)) {
		tokens.push_back(token);
	}
	
	return tokens;
}

int main() {
	
    cin >> n;
    
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	cout << dp[n - 1] << '\n';
    
    return 0;
}

