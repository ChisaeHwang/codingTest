#include <iostream>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int s=2; // 2 ���� ���μ����� 
    
    while(n>1){
    	if(n%s==0){
    		cout << s << '\n'; // ���μ� ���� �����ϸ� ��� 
    		n /= s; // ���μ����� ��Ų��ŭ ������ 
		} else {
			s++;	// ���μ����� �ȵ� �� ���� �μ� �ϳ��� �÷��� ������ �õ� 
		}
	}
    
    return 0;
}
