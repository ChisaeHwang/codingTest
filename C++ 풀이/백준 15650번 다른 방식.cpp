#include <iostream>
#include <algorithm>

using namespace std;

// ���������� ����� ��� ���� 
// ����� 
int a[10]; 

void go(int idx, int selected, int n, int m) { // index��°�� ä������ 
	if (selected == m){
		for(int i=0; i<m; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return; //������ ��� 
	}
	
	if(idx > n) return;
	a[selected] = idx; // idx ��� �߰� 
	go(idx+1, selected+1, n, m);
	a[selected] = 0 // idx ��� �߰� ����
	go(idx+1, selected, n, m); 
	
}

// go(0, 1, n, m)

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	
	return 0; 
	
}
