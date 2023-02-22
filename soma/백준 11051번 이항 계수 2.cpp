#include <bits/stdc++.h>

using namespace std;

int cache[1001][1001];
int a, b;

int bino(int n, int k) {
	
	if (k == 0 || n == k) {
		return 1;
	}
	
	if (cache[n][k] != -1) return cache[n][k] % 10007;
	
	
	return cache[n][k] = bino(n - 1, k - 1) + bino(n - 1, k);
} 

int main() {
	
	cin >> a >> b;
	
	fill(&cache[0][0], &cache[1001][1001], -1);
	
	cout << bino(a, b) << '\n';
	
	
	return 0;
}
