#include <iostream>
#include <algorithm>

using namespace std;

// ��� true false // ����� 
bool c[10]; int num[10]; int a[10]; 

void go(int idx, int n, int m) { // index��°�� ä������ 
	if (idx == m){
		for(int i=0; i<m; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return; //������ ��� 
	}
	for (int i=0; i<n; i++){
		if(c[i]) continue;
		c[i] = true; a[idx] = num[i];
		go(idx+1, n, m);
		c[i] = false;
	}
}

// go(0, 1, n, m)

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	sort(num, num+n);
	go(0, n, m);
	
	return 0; 
	
}
