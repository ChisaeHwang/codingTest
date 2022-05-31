#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool next_permutation(int *a, int n){
	int i = n-1; 
	while(i > 0 && a[i-1] >= a[i]) i -= 1; // �ڿ������� ������ ������������ ã�ƺ��� 
	// while���� �������������� i�� ���������� �����ϴ� �κ� 
	if(i <= 0) return false; // ������ ����
	
	int j = n-1;
	while(a[j] <= a[i-1]) j -= 1;// �������� �ٷ� ���� ���ں��� ó������ ū j�� �ڿ������� ã�� 
	swap(a[i-1], a[j]); // �ΰ� Swap 
	
	j = n-1; // ������ ������ �ڸ� 
	while(i < j){ // ���������� ���ۺκк��� ������ �ڸ����� ������ 
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
