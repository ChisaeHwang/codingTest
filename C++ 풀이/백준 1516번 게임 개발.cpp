#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct MyStruct
{
	int time;
	vector <int> prev;

}val;
val arr[501];
int n;
int dp[501];

int go(int num) {

	if (dp[num] != 0) return dp[num];


	int maxed = 0;
	for (int i = 0; i < arr[num].prev.size(); i++) {
		maxed = max(maxed, go(arr[num].prev[i]));
	}
	dp[num] = maxed + arr[num].time;
	return dp[num];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].time;
		int temp;
		while (1) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			arr[i].prev.push_back(temp);
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << go(i) << '\n';

	return 0;
}
