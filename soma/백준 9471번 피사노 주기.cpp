#include <iostream>
using namespace std;

long long pisano(long long m) {
    long long previous = 0;
    long long cur = 1;
    long long temp;

    for (long long i = 0; i < m * m; i++) {
        temp = (previous + cur) % m;
        previous = cur;
        cur = temp;

        if (previous == 0 && cur == 1) {
            return i + 1;
        }
    }
}

int main() {
	
	int t;
	
	cin >> t;
	
	while(t--) {
		int num, m;
		
		cin >> num >> m;
		
		cout << num << " " << pisano(m) << '\n';
	}
	
	
    return 0;
}

