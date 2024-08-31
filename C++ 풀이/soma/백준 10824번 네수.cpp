#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b, c, d;	//자연수를 입력받을 string변수
	long long num1, num2 = 0;	

	cin >> a >> b >> c >> d;

	a += b;	//a 뒤에 b를 붙이고
	c += d;	//c 뒤에 d를 붙인다

	num1 = stoll(a);	//붙인 string을 숫자로 변환한다. int의 범위를 벗어나는 문자열이 입력될 수 있기때문에 stoll 사용
	num2 = stoll(c);

	cout << num1 + num2;	//숫자로 변환된 두수의 합을 출력

	return 0;
}
