#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check(string &password){
	int ja = 0; // ���� 
	int mo = 0; // ����
	
	for (char x : password){
		if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
			mo += 1;
		} else {
			ja += 1;
		}
	} 
	
	// �ּ� �� ���� ����(a, e, i, o, u)�� �ּ� �� ���� �������� ����
	return ja >= 2 && mo >= 1;
}

// n : ������ �ϴ� ��ȣ�� ����
// alpah : ����� �� �ִ� ���ĺ�
// password : ������� ���� ��ȣ
// i : ������� ���� �����ؾ� �ϴ� ���ĺ��� �ε��� 
 
void go(int n, vector<char> &alpah, string password, int i) {
	if(password.length() == n){ // ������ ã�� ��� 
		if(check(password)){
			cout << password << '\n';	
		} 
		return;
	} 
	
	// �̰� ���� ������ �������� ������ ��ȣ�� ���� ���� ���� 
	if( i >= alpah.size()) return; // �Ұ����� ���
	go(n, alpah, password+alpah[i], i+1); // i��° ���ĺ��� ����ϴ� ��� 
	go(n, alpah, password, i+1); // i��° ���ĺ��� ������� �ʴ� ��� 
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<char> a(m); // ���� ũ�� ���� 
	
	for(int i=0; i<m; i++){
		cin >> a[i];
	}
	
	// ���������� ��� 
	sort(a.begin(), a.end());
	
	// ����, ��밡���� ���ĺ�, ������� ���� ��ȣ, ��ȣ �ε��� 
	go(n, a, "", 0);
	
	return 0;
}
