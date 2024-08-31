#include <iostream>
using namespace std;
long long memo[100] = {0,1,};
long long fibo(int N)
{
    if(N == 0 || N == 1)
        return memo[N];
    else if(memo[N] == 0)
        memo[N] = fibo(N-1) + fibo(N-2);
    return memo[N];
}

int main() {
    int N;
    cin >> N;
    cout << fibo(N);
}
