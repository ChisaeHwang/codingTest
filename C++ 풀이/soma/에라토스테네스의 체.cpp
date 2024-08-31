#include <iostream>

using namespace std;

bool prime[101]; 

void solve(int n) {
    prime[0] = prime[1] = false; 

    for(int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
	
	int n;
	
	cin >> n;

	fill(prime, prime + 101, true);
	
    solve(n);
    
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    
    return 0;
}
