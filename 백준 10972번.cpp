#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool next_permutation(int *a, int n){
	int i = n-1; 
	while(i > 0 && a[i-1] >= a[i]) i -= 1; // 뒤에서부터 어디까지 내림차순인지 찾아보기 
	// while문을 빠져나왔을떄의 i가 내림차순의 시작하는 부분 
	if(i <= 0) return false; // 마지막 순열
	
	int j = n-1;
	while(a[j] <= a[i-1]) j -= 1;// 내림차순 바로 앞의 숫자보다 처음으로 큰 j를 뒤에서부터 찾기 
	swap(a[i-1], a[j]); // 두개 Swap 
	
	j = n-1; // 순열의 마지막 자리 
	while(i < j){ // 내림차순의 시작부분부터 마지막 자리까지 뒤집기 
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
		cin >> a[i];
	}
	
	if(next_permutation(a.begin(), a.end())){
		for(int i=0; i<n; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	else cout << -1 << '\n';
	
	return 0;
} 
