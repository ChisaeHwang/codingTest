#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int n;

int solve(int n) {
	
	int num = n;
	
	num = num * 3.3;
	
	n = n - (num / 100);
	
	return n;
}

int main() {

 	cin >> n;

	cout << solve(n) << '\n';
	
 	return 0;
}
