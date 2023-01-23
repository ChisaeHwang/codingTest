#include <bits/stdc++.h>

using namespace std;

int t, n;
	int arr[1000001]={1,1,1,0,};

// �ð��ʰ� Ǯ�� 

bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) { // ������ �������ؼ� n���� �ּ��� ������ 2��ŭ �۾ƾ��� 
		if (n % i == 0) return 0;
	}
	
	return 1; 
}

int main() {
	
  for(int i=2; i*i<1000000; i++)
  {
    if(arr[i]==0) 
    for(int j=i*i; j<1000000; j+=i)
	    {
	      arr[j] = 1; // true�� �Ҽ��� �ƴ� 
	    }
  }
  
	for (int i = 0; i < 100; i++) {
		if (arr[i])  cout << i << " ";
	}

	
	while(true) {
		
		cin >> n;
		
		if (n == 0 || n <= 4) break;
		
		vector<int> v;
		
		if (n % 2 != 0) cout << "Goldbach's conjecture is wrong." << '\n';
		
		for (int i = 3; i <= n; i++) {
			for (int j = n; j >= 0; j--) {
				if (check(i) && check(j) && i + j == n) {
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		
		cout << n << " = " << v[0] << " + " << v[1] << '\n';
		
	}
	
	
	return 0;
}
