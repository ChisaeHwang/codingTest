#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool next_permutation(int *a, int n){
	int i = n-1; // 1
	while(i > 0 && a[i-1] >= a[i]) i -= 1;
	if(i <= 0) return false; // 마지막 순열
	
	int j = n-1; // 2
	while(a[j] <= a[i-1]) j -= 1;
	swap(a[i-1], a[j]); // 3
	
	j = n-1; // 4
	while(i < j){
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	
	return true;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	
	for(int i=0; i<n; i++){
		a[i] = i+1; // i-n
	}
	
	do {
		 for (int i=0; i<n; i++) {
			 cout << a[i] << ' ';
		 }
	 	cout << '\n';
	 } while (next_permutation(a.begin(), a.end()));
	
	return 0;
} 
