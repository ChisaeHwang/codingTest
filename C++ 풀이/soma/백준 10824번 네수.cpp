#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b, c, d;	//�ڿ����� �Է¹��� string����
	long long num1, num2 = 0;	

	cin >> a >> b >> c >> d;

	a += b;	//a �ڿ� b�� ���̰�
	c += d;	//c �ڿ� d�� ���δ�

	num1 = stoll(a);	//���� string�� ���ڷ� ��ȯ�Ѵ�. int�� ������ ����� ���ڿ��� �Էµ� �� �ֱ⶧���� stoll ���
	num2 = stoll(c);

	cout << num1 + num2;	//���ڷ� ��ȯ�� �μ��� ���� ���

	return 0;
}
