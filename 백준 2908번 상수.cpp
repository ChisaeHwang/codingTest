#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int reverse(int a){
	
	int ans = 0;
	
	for(int i = a; i; i/= 10)
	{
		ans = ans * 10 + i % 10;
	}
	
	return ans;
}

int main() {
	
	int n, m;
	
	cin >> n >> m;
	
	n = reverse(n);
	m = reverse(m);
	
	if(n > m)
	{
		cout << n << '\n';
	} 
	else
	{
		cout << m << '\n';
	}
	
	return 0;
}
