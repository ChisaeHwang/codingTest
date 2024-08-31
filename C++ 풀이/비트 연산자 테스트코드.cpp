#include <bits/stdc++.h>
using namespace std; 

void t1(){
	int n = 15;
	int idx = 0;   
	n &= ~(1 << idx);
	cout << "1. idx��° ��Ʈ������ : " << n << "\n";
}
void t2(){
	int n = 5;  //1001
	int idx = 0;  
	n ^= (1 << idx);
	cout << "2. 0�� 1��, 1�� 0���� XOR T2 : " << n << "\n";
}
void t3(){
	int n = 6;
	int idx = (n & -n); 
	cout << "3. ������ �����ִ� �ε��� T3: " << idx << "\n";
}
void t4(){
	int n = 4;  
	cout << "4. ũ�Ⱑ n�� ��� ������ ��� ��Ʈ �ѱ� T4 : " << (1 << n) - 1 << "\n";
}
void t5(){
	int n = 8;
	int idx = 2;   
	n |= (1 << idx);  
	cout << "5. idx��° ���ѱ� T5 : " << n << "\n";
}

void t6(){
	int n = 15; // 1111
	int idx = 0;   
	string a = n & (1 << idx) ? "yes" : "no";
	cout << "6. idx��° ��Ʈ�� �ִ��� Ȯ���ϱ� T6 : " << a << "\n";
}

int main() {   
	t1();
	t2();
	t3();
	t4();
	t5();
	t6(); 
    return 0;
}
/*
1. idx��° ��Ʈ������ : 14
2. 0�� 1��, 1�� 0���� XOR T2 : 4
3. ������ �����ִ� �ε��� T3: 2
4. ũ�Ⱑ n�� ��� ������ ��� ��Ʈ �ѱ� T4 : 15
5. idx��° ���ѱ� T5 : 12
6. idx��° ��Ʈ�� �ִ��� Ȯ���ϱ� T6 : yes
*/
[��ó] [�˰��� ����] 4����. ��Ʈ����ŷ|�ۼ��� ū��
