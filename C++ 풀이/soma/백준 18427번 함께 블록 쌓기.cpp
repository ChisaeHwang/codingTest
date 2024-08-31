#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> blocks;
	
int solve(int N, int H) {
	
	if(H == 0) return 1;
	if(N == 0) return 0;
	
	int &ret = dp[N][H];
	if(ret != -1) return ret;

	ret = solve(N - 1, H); 
	for(int block : blocks[N - 1]) {
		if(H >= block) {
			ret = (ret + solve(N - 1, H - block)) % 10007;	
		}
	}
	
	return ret;
}

int main() {
	
	int n, m, h;
		
	cin >> n >> m >> h;
	cin.ignore();
	
	blocks.resize(n);
	dp.assign(n + 1, vector<int>(h + 1, -1));
	
	string line;
	
	for(int i = 1; i <= n; i++) {
		getline(cin, line);
		istringstream str(line);
		int height;
		while(str >> height) {
			blocks[i - 1].push_back(height);
		}
	}
	
	cout << solve(n, h) << '\n';
	
	
	return 0;
	
}
