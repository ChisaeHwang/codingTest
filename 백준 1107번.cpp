#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool broken[10];
int possible(int c) {
	if(c == 0){
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while(c > 0){
		if(broken[c % 10]) return 0; // ������ ��ȣ���� 0�� ��� 
		len += 1;
		c /= 10;
	}
	
	return len;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; // ���� ���� ä��, �μ� ������ ��ư �� 
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int x; // �μ��� ������ ���� 
		cin >> x;
		broken[x] = true;
	}
	
	int ans = n - 100;
	if(ans < 0){ // ans�� - �Ǹ� ����ó�� 
		ans = -ans;
	}
	
	for(int i=0; i<=1000000; i++){
		int c = i; // �̵��� ä�� 
		int len = possible(c); // ���ڹ�ư �� ������ 
		if(len > 0){  
			int press = c - n; // + 
			if(press < 0){
				press = -press; // -
			}
			if(ans > len + press){ // ���ڴ��� Ƚ�� + �÷��� ���̳ʽ� Ƚ�� ���ϱ� 
				ans = len + press;
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
